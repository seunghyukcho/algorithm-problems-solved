#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>

#define MAXSIZE 2010
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

    void clear()
    {
        E.clear();
        for(int i = 0; i < MAXSIZE; i++)
        {
            V[i].clear();
            start[i] = 0;
        }
    }

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

map<string, set<int> > m;
int n;

void longestSuffix(string& s1, string& s2, string& ret)
{
    ret = "";
    int start1 = s1.size() - 1, start2 = s2.size() - 1;
    for(; start1 >= 0 && start2 >= 0 && s1[start1] == s2[start2]; start1--, start2--)
    {
        ret += s1[start1];
    }

    reverse(ret.begin(), ret.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, T;
    for(cin >> T; t <= T; t++)
    {
        int idx;

        cout << "Case #" << t << ": ";
        m.clear();
        G.clear();

        cin >> n;

        vector<string> ss = vector<string>(n + 1);
        G.source = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> ss[i + 1];
            G.setEdge(G.source, i + 1, 1);
        }

        string s;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                longestSuffix(ss[i], ss[j], s);
                if(s != "")
                {
                    m[s].insert(i);
                    m[s].insert(j);
                }
            }
        }

        G.sink = n + m.size() + 1;
        idx = n + 1;

        for(auto p : m)
        {
            for(int ele : p.second)
            {
                G.setEdge(ele, idx, 1);
            }

            G.setEdge(idx, G.sink, 2);
            idx++;
        }

        cout << G.maxflow() << '\n';
    }
}