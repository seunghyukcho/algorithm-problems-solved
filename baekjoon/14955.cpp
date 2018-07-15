#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXSIZE 110
#define MAX 100000000

using namespace std;

struct FlowGraph {
    int capacity[MAXSIZE][MAXSIZE];
    int source, sink, level[MAXSIZE], start[MAXSIZE];
    vector<int> V[MAXSIZE];

    void setEdge(int u, int v, int c) {
        if(capacity[u][v] == 0) {
            capacity[u][v] = c;
            capacity[v][u] = c;
            V[u].push_back(v);
            V[v].push_back(u);
        } else {
            capacity[u][v] += c;
            capacity[v][u] += c;
        }
    }

    void levelGraph() {
        queue<int> q;
        for(int i = 0; i < MAXSIZE; i++) level[i] = -1;

        level[source] = 0;
        q.push(source);

        while(!q.empty()) {
            int here = q.front(); q.pop();

            for(int next : V[here]) {
                if(level[next] == -1 && capacity[here][next]) {
                    level[next] = level[here] + 1;
                    q.push(next);
                }
            }
        }
    }

    long long dfs(int u, int minFlow = MAX) {
        if(u == sink) return minFlow;

        for(; start[u] < V[u].size(); start[u]++) {
            int next = V[u][start[u]];

            if(level[next] == level[u] + 1 && capacity[u][next]) {
                long long f = dfs(next, min(minFlow, capacity[u][next]));
                if(f) {
                    capacity[u][next] -= f;
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
struct Edge {
    int start, end, cost;
} E[502];
bool comp(Edge e1, Edge e2) { return e1.cost < e2.cost; }

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        E[i] = {s, e, c};
    }
    sort(E, E + m, comp);

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int i = 1; i <= n; i++) {
            for(int next : G.V[i]) {
                G.capacity[i][next] = 0;
                G.capacity[next][i] = 0;
            }

            G.V[i].clear();
        }

        Edge e = E[i];
        G.source = e.start;
        G.sink = e.end;

        for(int j = 0; j < i; j++) {
            Edge input = E[j];

            G.setEdge(input.start, input.end, 1);
        }

        ans += G.maxflow();
    }

    cout << ans << '\n';

    return 0;
}
