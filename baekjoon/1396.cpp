#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int start, end;
    int cost;
} E[100002];

struct Query
{
    int u, v, ans[2];
} Q[100002];

bool comp(Edge& e1, Edge& e2)
{
    return e1.cost < e2.cost;
}

int n, m, q, parent[100002], R[100002], sz[100002];

int find(int u)
{
    if(parent[u] != u) parent[u] = find(parent[u]);
    
    return parent[u];
}

void merge(int u, int v)
{
    int p1 = find(u), p2 = find(v);
    if(p1 == p2) return;

    if(R[p1] == R[p2])
    {
        parent[p2] = p1;
        sz[p1] += sz[p2];
        R[p1]++;
    }
    else if(R[p1] > R[p2]) 
    {
        parent[p2] = p1;
        sz[p1] += sz[p2];
    }
    else 
    {
        parent[p1] = p2;
        sz[p2] += sz[p1];
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> E[i].start >> E[i].end >> E[i].cost;
    sort(E, E + m, comp);
    
    cin >> q;
    for(int i = 0; i < q; i++) cin >> Q[i].u >> Q[i].v;

    vector<int> start(q + 1, 0), end(q + 1, m);
    while(true)
    {
        bool flag = true;
        vector<vector<int> > here(m + 1);
        for(int i = 0; i < q; i++)
        {
            if(start[i] != end[i]) 
            {
                here[(start[i] + end[i]) / 2].push_back(i);
                flag = false;
            }
        }
        if(flag) break;

        for(int i = 1; i <= n; i++) 
        {
            parent[i] = i;
            R[i] = 1;
            sz[i] = 1;
        }

        for(int i = 0; i < m; i++)
        {
            merge(E[i].start, E[i].end);
            for(int idx : here[i])
            {
                int u = Q[idx].u, v = Q[idx].v;
                int p1 = find(u), p2 = find(v);

                if(p1 == p2) 
                {
                    end[idx] = i;
                    Q[idx].ans[0] = E[i].cost;
                    Q[idx].ans[1] = sz[p1];
                }
                else start[idx] = i + 1;
            }
        }
    }

    for(int i = 0; i < q; i++) cout << Q[i].ans[0] << ' ' << Q[i].ans[1] << '\n';
}