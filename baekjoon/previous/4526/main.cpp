#include<iostream>
#include<vector>

using namespace std;

void post_order(vector<int> &a, vector<int> &b, int f1, int l1, int f2, int l2){
    if(f1 > l1 || f2 > l2)return;
    else if(f1 == l1){
        cout << a[f1] << ' ';
        return;
    }
    int num = a[f1];
    int i;
    for(i = f2; i <= l2; i++){
        if(b[i] == num)break;
    }
    post_order(a, b, f1+1, f1+i-f2, f2, i-1);
    post_order(a, b, f1+i-f2+1, f1+l2-f2, i+1, l2);
    cout << num << ' ';
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> preorder(n);
        vector<int> inorder(n);
        for(int j = 0; j < n; j++)cin >> preorder[j];
        for(int j = 0; j < n; j++)cin >> inorder[j];
        post_order(preorder, inorder, 0, n-1, 0, n-1);
        cout << '\n';
    }

    return 0;
}

