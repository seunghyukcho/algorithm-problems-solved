#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define x first
#define y second

using namespace std;

typedef pair<int, int> point;
typedef pair<int, int> edge;

struct Area
{
    int idx;
    point left, right;
};

bool intersects(Area a1, Area a2)
{
    if(a1.left.x > a2.left.x) return intersects(a2, a1);

    if(a1.right.y <= a2.left.y || a1.right.x <= a2.left.x || a1.left.y >= a2.right.y) return false;
    else return true;
}

struct Gang
{
    Area areas[20];
} G[302];

int n, m, scc[9002];
vector<int> graph[9002], rgraph[9002], st;
bool visited[9002];

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
    scc[here] = num;
    visited[here] = true;

    for(int next : rgraph[here])
    {
        if(!visited[next]) dfs2(next, num);
    }
}

int main()
{
    int nodes = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            Area& area = G[i].areas[j];
            area.idx = nodes;
            nodes += 2;

            cin >> area.left.x >> area.left.y >> area.right.x >> area.right.y;
        }

        for(int j = 0; j < m; j++)
        {
            int here = G[i].areas[j].idx;
            for(int k = j + 1; k < m; k++)
            {
                int next = G[i].areas[k].idx;

                graph[here ^ 1].push_back(next);
                graph[next ^ 1].push_back(here);

                rgraph[next].push_back(here ^ 1);
                rgraph[here].push_back(next ^ 1);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(Area area : G[i].areas)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(Area area2 : G[j].areas)
                {
                    if(intersects(area, area2))
                    {
                        int here = area.idx, next = area2.idx;

                        graph[here].push_back(next ^ 1);
                        graph[next].push_back(here ^ 1);

                        rgraph[next ^ 1].push_back(here);
                        rgraph[here ^ 1].push_back(next);
                    }
                }
            }
        }
    }

    for(int i = 0; i < nodes; i++)
    {
        if(!visited[i]) dfs1(i);
    }

    reverse(st.begin(), st.end());
    memset(visited, false, sizeof(visited));

    int sccnum = 1;
    for(int here : st)
    {
        if(!visited[here]) dfs2(here, sccnum++);
    }

    for(int i = 0; i < nodes; i += 2)
    {
        if(scc[i] == scc[i ^ 1]) 
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}