#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
#define MAXSIZE 300

using namespace std;

struct Edge {
    int idx;
    int start, end, capacity;
};

struct FlowGraph {
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

    long long dfs(int u, int minFlow = INT_MAX) {
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
        for(int i = 0; i < MAXSIZE; i++) 
            V[i].clear();
    }
} G;

int n, c[102], d[102];

bool check(int minCost)
{
    bool result;

    G.clear();
    G.source = 0;
    G.sink = 2 * n + 1;

    for(int i = 0; i < n; i++)
    {
        G.setEdge(0, i + 1, 1);
        G.setEdge(n + i + 1, 2 * n + 1, 1);

        for(int j = 0; j < n; j++)
        {
            int cost = c[i] ^ d[j];
            if(cost >= minCost)
                G.setEdge(i + 1, n + j + 1, 1);
        }
    }

    result = (G.maxflow() == n);

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        cin >> d[i];

    
    int start = 0, end = INT_MAX;
    while(start + 1 < end)
    {
        long long mid = (start + (long long)end) / 2;

        if(check(mid))
            start = mid;
        else
            end = mid - 1;
    }

    if(check(end))
        cout << end << '\n';
    else
        cout << start << '\n';
}