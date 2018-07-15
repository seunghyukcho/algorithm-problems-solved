#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXSIZE 2010
#define MAX 100000000

using namespace std;

struct FlowGraph {
    int capacity[MAXSIZE][MAXSIZE];
    int source, sink, level[MAXSIZE], start[MAXSIZE];
    vector<int> V[MAXSIZE];

    void setEdge(int u, int v, int c) {
        if(capacity[u][v] == 0) {
            capacity[u][v] = c;
            V[u].push_back(v);
            V[v].push_back(u);
        } else capacity[u][v] += c;
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
                    capacity[next][u] += f;
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

int n, m, k;

int main(){
    cin >> n >> m >> k;
    G.source = 0;
    G.sink = n + m + 1;

    G.setEdge(0, n + m + 2, k);
    for(int i = 1; i <= n; i++) {
        G.setEdge(n + m + 2, i, 1);
        G.setEdge(0, i, 1);

        int num;
        for(cin >> num; num > 0; num--) {
            int next;
            cin >> next;

            G.setEdge(i, n + next, 1);
        }
    }

    for(int i = 1; i <= m; i++) G.setEdge(i + n, n + m + 1, 1);


    cout << G.maxflow() << '\n';

    return 0;
}
