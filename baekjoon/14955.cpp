#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXSIZE 110
#define MAX 100000000

using namespace std;

struct FlowGraph {
    struct Edge {
        int idx;
        int start, end, capacity;
    };

    vector<Edge> E;
    vector<int> V[MAXSIZE];
    int source, sink, level[MAXSIZE], start[MAXSIZE];

    void setEdge(int u, int v, int c) {
        int n = E.size();

        E.push_back({n, u, v, c});
        E.push_back({n + 1, v, u, 0});

        V[u].push_back(n);
        V[v].push_back(n + 1);
    }

    void levelGraph() {
        queue<int> q;
        for(int i = 0; i < MAXSIZE; i++) level[i] = -1;

        level[source] = 0;
        q.push(source);

        while(!q.empty()) {
            int here = q.front(); q.pop();

            for(auto edge : V[here]) {
                int next = E[edge].end;
                if(level[next] == -1 && E[edge].capacity) {
                    level[next] = level[here] + 1;
                    q.push(next);
                }
            }
        }
    }

    long long dfs(int u, int minFlow = MAX) {
        if(u == sink) return minFlow;

        for(; start[u] < V[u].size(); start[u]++) {
            auto edge = E[V[u][start[u]]];
            int next = edge.end;

            if(level[next] == level[u] + 1 && edge.capacity) {
                long long f = dfs(next, min(minFlow, edge.capacity));
                if(f) {
                    E[edge.idx].capacity -= f;
                    E[edge.idx ^ 1].capacity += f;
                    return f;
                }
            }
        }

        return 0;
    }

    long long maxflow() {
        long long ret = 0;
        while(1) {
            levelGraph();
            if(level[sink] == -1) break;
            for(int i = 0; i < MAXSIZE; i++) start[i] = 0;
            while(1) {
                long long flow = dfs(source);
                if(flow == 0) break;
                ret += flow;
            }
        }

        return ret;
    }
} G;

int n, m;
struct Edge2 {
    int start, end, cost;
} E2[502];
bool comp(Edge2 e1, Edge2 e2) { return e1.cost < e2.cost; }

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        E2[i] = {s, e, c};
    }
    sort(E2, E2 + m, comp);

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int i = 1; i <= n; i++) G.V[i].clear();
        G.E.clear();

        Edge2 e = E2[i];
        G.source = e.start;
        G.sink = e.end;

        for(int j = 0; j < i && E2[j].cost < e.cost; j++) {
            Edge2 input = E2[j];

            G.setEdge(input.start, input.end, 1);
            G.setEdge(input.end, input.start, 1);
        }
        int result = G.maxflow();

        ans += result;
    }

    cout << ans << '\n';

    return 0;
}
