#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int anc[40002][20], dis[40002][20];
int parent[40002], cost[40002], level[40002];
vector<pair<int, int> > tree[40002];

int ancestor(int n, int k) {
    if(anc[n][k]) return anc[n][k];
    if(k == 0) return parent[n];
    else return anc[n][k] = ancestor(ancestor(n, k - 1), k - 1);
}

int dist(int n, int k) {
    if(dis[n][k]) return dis[n][k];
    if(k == 0) return cost[n];
    else return dis[n][k] = dist(n, k - 1) + dist(ancestor(n, k - 1), k - 1);
}

void init(int here, int prev) {
    //cout << here << ' ' << prev << '\n';
    parent[here] = prev;
    level[here] = level[prev] + 1;

    for(auto edge : tree[here]) {
        int next = edge.first;
        int c = edge.second;

        if(next == prev) continue;
        cost[next] = c;
        init(next, here);
    }
}

pair<int, int> find_parent(int n, int h) {
    int sum = 0;
    for(int i = 0; h > 0; h /= 2, i++) {
        if(h % 2) {
            sum += dist(n, i);
            n = ancestor(n, i);
        }
    }

    return make_pair(n, sum);
}

int LCA(int u, int v) {
    //cout << u << ' ' << v << '\n';
    if(level[u] < level[v]) return LCA(v, u);
    if(level[u] > level[v]) {
        int diff = level[u] - level[v];
        auto ret = find_parent(u, diff);

        return ret.second + LCA(ret.first, v);
    }

    int s = 0, t = level[u];
    while(s + 1 < t) {
        int mid = (s + t) / 2;
        int parentu = find_parent(u, mid).first;
        int parentv = find_parent(v, mid).first;
        if(parentu == parentv) t = mid;
        else s = mid + 1;
    }

    auto parentu = find_parent(u, s);
    auto parentv = find_parent(v, s);

    if(parentu.first == parentv.first) return parentu.second + parentv.second;
    else {
        parentu = find_parent(u, t);
        parentv = find_parent(v, t);

        return parentu.second + parentv.second;
    }
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        tree[s].push_back({t, c});
        tree[t].push_back({s, c});
    }

    init(1, 1);

    //for(int i = 1; i <= n; i++) cout << i << ' ' << level[i] << ' ' << parent[i] << ' ' << cost[i] << '\n';

    cin >> m;
    for(int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        cout << LCA(s, t) << '\n';
    }

    return 0;
}
