#include<iostream>
#include<vector>

using namespace std;

void preorder(int f1, int l1, int f2, int l2, vector<int> &inorder, vector<int> &postorder){
    if(f1 > l1)return;
    cout << postorder[l2] << ' ';
    int i;
    for(i = f1; i <= l1; i++){
        if(inorder[i] == postorder[l2])break;
    }
    preorder(f1, i - 1, f2, f2 + i - f1 - 1, inorder, postorder);
    preorder(i + 1, l1, f2 + i - f1, l2 - 1, inorder, postorder);

    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for(int i = 0; i < n; i++)cin >> v1[i];
    for(int i = 0; i < n; i++)cin >> v2[i];

    preorder(0, n - 1, 0, n - 1, v1, v2);
    cout << '\n';
    return 0;
}
    
