#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, s, t;
vector<pair<int, int> > graph[100002];
vector<int> ans, rgraph[100002];
bool visited[100002], visited2[100002];

void dfs1(int here)
{
    visited2[here] = true;

    for(int next : rgraph[here])
    {
        if(visited2[next]) continue;
        dfs1(next);
    }
}

int dfs2(int here)
{
    visited[here] = true;
    if(here == t) return 1;

    for(auto edge : graph[here])
    {
        int next = edge.second;
        if(!visited2[next]) continue;
        if(visited[next]) return -1;

        ans.push_back(edge.first);
        int result = dfs2(next);
        if(result == 1 || result == -1) return result;
        ans.pop_back();
    }

    return 0;
}

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++)
    {
        int n1, n2, clr;
        cin >> n1 >> n2 >> clr;

        graph[n1].push_back({clr, n2});
        rgraph[n2].push_back(n1);
    }

    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
    
    dfs1(t);

    if(!visited2[s])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    memset(visited, false, sizeof(visited));
    int result = dfs2(s);
    if(result == 1)
    {
        for(int v : ans) cout << v << ' ';
        cout << '\n';
    }
    else cout << "TOO LONG\n";
    return 0;
}