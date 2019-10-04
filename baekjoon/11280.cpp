#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> edge;

int n, m, scc[20002];
vector<int> graph[20002], rgraph[20002], st;
bool visited[20002];

void set_edge(int src, int dest)
{
    graph[src].push_back(dest);
    rgraph[dest].push_back(src);
}

int convert(int idx)
{
    return idx > n ? idx - n : idx + n;
}

void dfs1(int here)
{
    visited[here] = true;
    for(int next : graph[here])
    {
        if(!visited[next]) dfs1(next);
    }

    st.push_back(here);
}

void dfs2(int here, int num)
{
    visited[here] = true;
    scc[here] = num;
    for(int next : rgraph[here])
    {
        if(!visited[next]) dfs2(next, num);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        a = (a < 0 ? -a + n : a);
        b = (b < 0 ? -b + n : b);

        set_edge(convert(a), b);
        set_edge(convert(b), a);
    }

    for(int i = 1; i <= 2 * n; i++)
    {
        if(!visited[i])
            dfs1(i);
    }

    reverse(st.begin(), st.end());
    memset(visited, false, sizeof(visited));

    int scc_num = 1;
    for(int here : st)
    {
        if(!visited[here])
            dfs2(here, scc_num++);
    }

    for(int i = 1; i <= n; i++)
    {
        if(scc[i] == scc[i + n])
        {
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << 1 << '\n';
    return 0;
}