#include<iostream>

using namespace std;

struct Node {
    int key;
    int priority, size;

    Node *left, *right;
    Node(const int _key): key(_key), priority(rand() % 50000), size(1), left(NULL), right(NULL) {
        // cout << priority << '\n';
    }

    void setLeft(Node* _left) {
        left = _left;
        calcSize();
    }

    void setRight(Node* _right) {
        right = _right;
        calcSize();
    }

    void calcSize() {
        size = 1;
        size += (left ? left->size : 0);
        size += (right ? right->size : 0);
    }
};

typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, int key) {
    if(!root) return NodePair(NULL, NULL);

    if(root->key < key) {
        NodePair result = split(root->right, key);
        root->setRight(result.first);
        return NodePair(root, result.second);
    }
    else {
        NodePair result = split(root->left, key);
        root->setLeft(result.second);
        return NodePair(result.first, root);
    }
}

Node* insert(Node* root, Node* node) {
    if(!root) return root = node;

    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root->key)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    return root;
}

Node* merge(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;

    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    else {
        a->setRight(merge(a->right, b));
        return a;
    }
}

Node* erase(Node* root, int key) {
    if(!root) return root;

    if(root->key == key) {
        Node* newRoot = merge(root->left, root->right);
        delete root;
        return newRoot;
    }
    else if(root->key > key)
        root->setLeft(erase(root->left, key));
    else
        root->setRight(erase(root->right, key));

    return root;
}

Node* kth_element(Node* root, int find) {
    int leftSize = (root->left ? root->left->size : 0);
    if(find <= leftSize) return kth_element(root->left, find);
    if(leftSize + 1 == find) return root;

    return kth_element(root->right, find - leftSize - 1);
}

int t, n, arr[50002];

int main(){
    srand(time(NULL));
    for(scanf("%d", &t); t > 0; t--) {
        Node* root = NULL;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            root = insert(root, new Node(i));
        }

        for(int i = n; i >= 1; i--) {
            int here = i - arr[i];
            Node* result = kth_element(root, here);
            arr[i] = result->key;
            root = erase(root, arr[i]);
        }

        for(int i = 1; i <= n; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}
