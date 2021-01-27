#include <iostream>
#include <algorithm>

using namespace std;

int n, m, level[1000002], back[1000002];
char map[1000002];
bool visited[1000002], reach[1000002];

int dfs(int x, int y, int l = 1)
{
    // cout << x << ' ' << y << '\n';
    int idx = m * x + y;
    level[idx] = l;
    back[idx] = idx;
    visited[idx] = true;

    if(x < n - 1 && !visited[idx + m])
    {
        int b = dfs(x + 1, y, l + 1);
        if(level[back[idx]] > level[b]) back[idx] = b;
    }
    if(y < m - 1 && !visited[idx + 1])
    {
        int b = dfs(x, y + 1, l + 1);
        if(level[back[idx]] > level[b]) back[idx] = b;
    }
    if(x > 0 && !visited[idx - m])
    {
        int b = dfs(x - 1, y, l + 1);
        if(level[back[idx]] > level[b]) back[idx] = b;
    }
    if(y > 0 && !visited[idx - 1])
    {
        int b = dfs(x, y - 1, l + 1);
        if(level[back[idx]] > level[b]) back[idx] = b;
    }

    if(x < n - 1 && map[idx + m] != '#') 
    {
        int next = idx + m;
        if(level[next] < level[back[idx]]) back[idx] = next;
    }
    if(y < m - 1 && map[idx + 1] != '#') 
    {
        int next = idx + 1;
        if(level[next] < level[back[idx]]) back[idx] = next;
    }
    if(x > 0 && map[idx - m] != '#') 
    {
        int next = idx - m;
        if(level[next] < level[back[idx]]) back[idx] = next;
    }
    if(y > 0 && map[idx - 1] != '#') 
    {
        int next = idx - 1;
        if(level[next] < level[back[idx]]) back[idx] = next;
    }
    
    cout << x << ' ' << y << ' ' << l << ' ' << back[idx] << '\n';

    return back[idx];
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> map[i * m + j];
            if(map[i * m + j] == '#') visited[i * m + j] = true;
        }
    
    dfs(0, 0);
    if(!visited[n * m - 1]) cout << 0 << '\n';
    else
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int idx = i * m + j;
                if(idx == 0 || idx == n * m - 1 || level[idx] == 0) continue;
                cout << i << ' ' << j << '\n';
                bool flag = false;
                if(i < n - 1 && level[idx + m] == level[idx] + 1)
                {
                    int next = idx + m;
                    if(level[back[next]] >= level[idx]) flag = true;
                }
                if(j < m - 1 && level[idx + 1] == level[idx] + 1)
                {
                    int next = idx + 1;
                    if(level[back[next]] >= level[idx]) flag = true;
                }
                if(i > 0 && level[idx - m] == level[idx] + 1)
                {
                    int next = idx - m;
                    if(level[back[next]] >= level[idx]) flag = true;
                }
                if(j > 0 && level[idx - 1] == level[idx] + 1)
                {
                    int next = idx - 1;
                    if(level[back[next]] >= level[idx]) flag = true;
                }

                if(flag)
                {
                    cout << 1 << '\n';
                    return 0;
                }
            }
        cout << 2 << '\n';
    }
}