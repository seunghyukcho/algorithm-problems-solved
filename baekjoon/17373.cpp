#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

typedef long long ll;

struct Node {
    int key;
    int priority, size;

    Node *left, *right;
    Node(const int _key): key(_key), priority(rand() % 1000000), size(1), left(NULL), right(NULL) {
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
}*root;

struct Query 
{
    ll val;
    int idx;
    pair<int, int> ans;
} Q[1000002];

bool comp1(const Query q1, const Query q2)
{
    return q1.val < q2.val;
}

bool comp2(Query& q1, Query& q2)
{
    return q1.idx < q2.idx;
}

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

Node* kth_element(Node* root, ll find) {
    int leftSize = (root->left ? root->left->size : 0);
    if(find <= leftSize) return kth_element(root->left, find);
    if(leftSize + 1 == find) return root;

    return kth_element(root->right, find - leftSize - 1);
}

void clean(Node *here)
{
    if(here->left) clean(here->left);
    if(here->right) clean(here->right);
    delete here;
}

ll sum[1000002];
int num[100002];
bool visited[1000002];
map<int, ll> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    root = NULL;

    cin >> n >> m >> q;
    
    for(int i = 0; i < n; i++) 
    {
        cin >> num[i];
        cnt[num[i]]++;
    }

    for(int i = 1; i <= m; i++)
    {
        auto f = cnt.find(i);
        if(f == cnt.end()) 
        {
            root = insert(root, new Node(i)); 
            sum[i] = m;
            visited[i] = true;
        }
    }

    for(int i = 0; i < q; i++)
    {
        cin >> Q[i].val;
        Q[i].idx = i;
        Q[i].ans = { -1, -1 };
    }

    sort(Q, Q + q, comp1);
    for(int i = 0; i < n; i++)
    {
        cnt[num[i]]--;
        if(cnt[num[i]] == 0)
        {
            root = insert(root, new Node(num[i]));
            cnt.erase(num[i]);
        }

        if(!visited[num[i]])
        {
            visited[num[i]] = true;
            sum[num[i]] = (root ? root->size : 0);
        }
    }

    for(int i = 1; i <= m; i++) sum[i] += sum[i - 1];
    clean(root);
    root = NULL;
    for(int i = 0; i < n; i++) cnt[num[i]]++;

    for(int i = 1; i <= m; i++)
    {
        auto f = cnt.find(i);
        if(f == cnt.end()) 
        {
            root = insert(root, new Node(i)); 

            ll start = sum[i - 1] + 1, end = sum[i];
            Query lb;
            lb.val = start;

            auto f = lower_bound(Q, Q + q, lb, comp1);
            for(; f < Q + q && f->val <= end; f++) f->ans = { i, f->val - start + 1 };
            
        }
        
        else visited[i] = false;
    }

    for(int i = 0; i < n; i++)
    {
        cnt[num[i]]--;
        if(cnt[num[i]] == 0)
        {
            root = insert(root, new Node(num[i]));
            cnt.erase(num[i]);
        }

        if(!visited[num[i]])
        {
            visited[num[i]] = true;
            ll start = sum[num[i] - 1] + 1, end = sum[num[i]];
            Query lb;
            lb.val = start;

            auto f = lower_bound(Q, Q + q, lb, comp1);
            
            for(; f < Q + q && f->val <= end; f++) 
            {
                Node *here = kth_element(root, f->val - start + 1);
                if(here != NULL) f->ans = { num[i], here->key };
            }
        }
    }

    sort(Q, Q + q, comp2);
    for(int i = 0; i < q; i++) 
    {
        Query q = Q[i];
        cout << q.ans.first << ' ' << q.ans.second << '\n';
    }
}