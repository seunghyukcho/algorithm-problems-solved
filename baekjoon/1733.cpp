#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 1000002

using namespace std;

vector<int> graph[MAXN];
int N, level[MAXN], A[MAXN], B[MAXN];

void bfs()
{
    memset(level, 0, sizeof(level));

    queue<int> q;
    for(int i = 1; i <= N; i++)
    {
        if(A[i] == 0) 
        {
            q.push(i);
            level[i] = 1;
        }
    }

    while(!q.empty())
    {
        int here = q.front(), l = level[here];
        q.pop();

        for(int next : graph[here])
        {
            if(B[next] && level[B[next]] == 0)
            {
                level[B[next]] = l + 1;
                q.push(B[next]);
            }
        }
    }
}

bool dfs(int here)
{
    for(int next : graph[here])
    {
        if(B[next] == 0 || (level[B[next]] == level[here] + 1 && dfs(B[next])))
        {
            A[here] = next;
            B[next] = here;
            return true;
        }
    }

    return false;
}

int main()
{
    int flow, total_flow = 0;

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[i].push_back(a);
        graph[i].push_back(b);
    }

    while(1)
    {
        flow = 0;

        bfs();
        for(int i = 1; i <= N; i++)
        {
            if(A[i] == 0 && dfs(i)) flow++;
        }

        if(!flow) break;
        total_flow += flow;
    }

    if(total_flow != N) cout << -1 << '\n';
    else
    {
        for(int i = 1; i <= N; i++) cout << A[i] << '\n';
    }

    return 0;
}