#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXSIZE 6500
#define MAX 100000000

using namespace std;

struct Shark {
    long long size, speed, intel;
} S[52];

int n;

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

    void clear() {
        E.clear();
        for(int i = 0; i < MAXSIZE; i++) V[i].clear();
    }
} G;

int main(){
    cin >> n;
    G.source = 0; G.sink = 2 * n + 1;

    for(int i = 1; i <= n; i++) {
        G.setEdge(0, i, 2);
        G.setEdge(n + i, 2 * n + 1, 1);

        cin >> S[i].size >> S[i].speed >> S[i].intel;

        for(int j = 1; j < i; j++){
            if(S[j].size <= S[i].size && S[j].speed <= S[i].speed && S[j].intel <= S[i].intel){
                if(!(S[j].size == S[i].size && S[j].speed == S[i].speed && S[j].intel == S[i].intel)) G.setEdge(i, n + j, 1);
            }
            if(S[j].size >= S[i].size && S[j].speed >= S[i].speed && S[j].intel >= S[i].intel)
                G.setEdge(j, n + i, 1);
        }
    }


    cout << n - G.maxflow() << '\n';

    return 0;
}
