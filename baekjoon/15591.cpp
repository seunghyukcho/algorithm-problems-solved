#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int> > tree[5002];

int dfs(int here, int prev, int k) {
    int ret = 1;
    for(auto edge : tree[here]) {
        int next = edge.first, cost = edge.second;

        if(next == prev) continue;
        if(cost >= k) ret += dfs(next, here, k);
    }

    return ret;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n - 1; i++) {
        int s, e, c;
        scanf("%d%d%d", &s, &e, &c);
        tree[s].push_back({e, c});
        tree[e].push_back({s, c});
    }

    for(int i = 0; i < q; i++) {
        int k, v;
        scanf("%d%d", &k, &v);
        int ans = 0;
        for(auto edge : tree[v]) {
            if(edge.second >= k) ans += dfs(edge.first, v, k);
        }
        printf("%d\n", ans);
    }

    return 0;
}
