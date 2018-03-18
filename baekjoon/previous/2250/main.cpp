#include<iostream>
#include<vector>

using namespace std;

int a[10001][2];

int min(int a, int b){
    return a > b ? b : a;
}
int max(int a, int b){
    return a > b ? a : b;
}
int tree(vector<vector<int> >& node, int num, int level, int ans){
    if(num == -1)return ans;

    int l = node[num][0];
    int r = node[num][1];
    int col = tree(node, l, level + 1, ans) + 1;
    a[level][0] = min(a[level][0], col);
    a[level][1] = max(a[level][1], col);
    return tree(node, r, level + 1, col);
}

int main(){
    int n, root;
    cin >> n;
    vector<vector<int> > node(n+1, vector<int>(2, 0));
    vector<int> parent(n+1, 0);
    
    for(int i = 1; i <= n; i++){
        int here;
        cin >> here;
        cin >> node[here][0] >> node[here][1];
        if(node[here][0] != -1)parent[node[here][0]] = here;
        if(node[here][1] != -1)parent[node[here][1]] = here;
        a[i][0] = 1e9;
        a[i][1] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(!parent[i])root = i;
    }
    tree(node, root, 1, 0);
    int ans[2] = {0, 0};
    for(int i = 1; i <= n; i++){
        if(ans[1] < a[i][1] - a[i][0] + 1){
            ans[0] = i;
            ans[1] = a[i][1] - a[i][0] + 1;
        }
    }

    cout << ans[0] << ' ' << ans[1]  << '\n';

    return 0;
}
