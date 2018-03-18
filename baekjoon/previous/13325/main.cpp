#include<iostream>
#include<vector>

using namespace std;

int ans;

int dfs(int n, vector<int> &v){
    if(2 * n > v.size())
        return 0;

    int r = dfs(2 * n, v) + v[2 * n];
    int l = dfs(2 * n + 1, v) + v[2 * n + 1];
    ans += v[2 * n] + v[2 * n + 1] + abs(r - l);
    return min(r, l) + abs(r - l);
}

int main(){
    int k;
    cin >> k;

    vector<int> tree;
    tree.push_back(0);
    tree.push_back(0);
    for(int i = 0; i < (1 << (k + 1)) - 2; i++){
        int num;
        cin >> num;
        tree.push_back(num);
    }
    
    dfs(1, tree);
    cout << ans << '\n';

    return 0;
}

