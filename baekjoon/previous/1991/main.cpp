#include<iostream>
#include<vector>

using namespace std;

struct node{
    char name;
    node* left = NULL;
    node* right = NULL;
};

void preorder(node* root){
    if(root == NULL)return;
    cout << root->name;
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root == NULL)return;
    inorder(root->left);
    cout<<root->name;
    inorder(root->right);
}
void postorder(node* root){
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->name;
}
int main(){
    int n;
    cin >> n;
    vector<node> tree(30);
    for(int i = 0; i < n; i++){
        char name;
        char c1, c2;
        cin >> name >> c1 >> c2;
        tree[name - 'A'].name = name;
        if(c1 != '.')tree[name - 'A'].left = &tree[c1 - 'A'];
        if(c2 != '.')tree[name - 'A'].right = &tree[c2 - 'A'];
    }
    preorder(&tree[0]);
    cout << '\n';
    inorder(&tree[0]);
    cout << '\n';
    postorder(&tree[0]);
    cout << '\n';

    return 0;
}
