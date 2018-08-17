#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int> > tree[100002];

void dfs(int here, int prev, int finish, vector<int>& v) {
    if(here == finish) {
        int sum = 0, mx = 0;
        for(int edge : v) {
            sum += edge;
            mx = max(mx, edge);
        }

        cout << sum - mx << '\n';
        return;
    }

    for(auto next : tree[here]) {
        if(prev == next.first) continue;

        v.push_back(next.second);
        dfs(next.first, here, finish, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, start, end;
    cin >> n >> start >> end;
    for(int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }

    vector<int> v;
    dfs(start, 0, end, v);

    return 0;
}
