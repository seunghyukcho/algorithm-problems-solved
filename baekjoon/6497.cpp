#include<iostream>
#include<algorithm>

using namespace std;

struct Edge {
    int start, end, cost;
} E[200002];

bool comp(Edge e1, Edge e2) { return e1.cost < e2.cost; }

int n, m, ans, parent[200002];
int find(int v) {
    return parent[v] = (v == parent[v]) ? v : find(parent[v]);
}
void merge(int u, int v) {
    parent[find(u)] = find(v);
}
bool issame(int u, int v) {
    return find(u) == find(v);
}

int main(){
    ios::sync_with_stdio(false);
    for(;;) {
        ans = 0;
        cin >> m >> n;
        if(m == 0 && n == 0) break;

        for(int i = 0; i < m; i++) parent[i] = i;
        for(int i = 0; i < n; i++) {
            cin >> E[i].start >> E[i].end >> E[i].cost;
            ans += E[i].cost;
        }

        sort(E, E + n, comp);
        for(int i = 0; i < n; i++) {
            auto edge = E[i];
            if(!issame(edge.start, edge.end)) {
                merge(edge.start, edge.end);
                ans -= edge.cost;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
