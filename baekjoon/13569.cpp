#include<bits/stdc++.h>

using namespace std;

const int MAXSIZE = 500, MAX = 1000000000;
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

int n, m, indemand[MAXSIZE], outdemand[MAXSIZE], demandsum;
double experiment[202][202], row[202], col[202];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    G.source = n + m + 2, G.sink = n + m + 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> experiment[i][j];
        cin >> row[i];
    }
    for(int i = 1; i <= m; i++) cin >> col[i];

    for(int i = 1; i <= n; i++) {
        int capacity, demand;
        for(int j = 1; j <= m; j++) {
            capacity = ceil(experiment[i][j]), demand = floor(experiment[i][j]);
            outdemand[i] += demand;
            indemand[n + j] += demand;

            G.setEdge(i, n + j, capacity - demand);
        }

        capacity = ceil(row[i]), demand = floor(row[i]);
        outdemand[0] += demand;
        indemand[i] += demand;

        G.setEdge(0, i, capacity - demand);
    }

    for(int i = 1; i <= m; i++) {
        int capacity = ceil(col[i]), demand = floor(col[i]);
        outdemand[n + i] += demand;
        indemand[n + m + 1] += demand;

        G.setEdge(n + i, n + m + 1, capacity - demand);
    }

    for(int i = 0; i <= n + m + 1; i++) {
        demandsum += indemand[i];
        G.setEdge(G.source, i, indemand[i]);
        G.setEdge(i, G.sink, outdemand[i]);
    }

    G.setEdge(n + m + 1, 0, MAX);

    int maxflow = G.maxflow();
    assert(maxflow == demandsum);

    for(int edge : G.V[0]) {
        int next = G.E[edge].end;
        if(next >= 1 && next <= n) row[next] = ceil(row[next]) - G.E[edge].capacity;
    }

    for(int edge : G.V[n + m + 1]) {
        int next = G.E[edge].end;
        if(next >= n + 1 && next <= n + m) col[next - n] = floor(col[next - n]) + G.E[edge].capacity;
    }

    for(int i = 1; i <= n; i++) {
        for(int edge : G.V[i]) {
            int next = G.E[edge].end;
            if(next >= n + 1 && next <= n + m) experiment[i][next - n] = ceil(experiment[i][next - n]) - G.E[edge].capacity;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << experiment[i][j] << ' ';
        }
        cout << row[i] << '\n';
    }
    for(int i = 1; i <= m; i++) cout << col[i] << ' ';
    cout << '\n';
}
