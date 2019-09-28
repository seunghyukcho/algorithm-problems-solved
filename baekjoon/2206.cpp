#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct coor
{
    int x, y, broken, dist;
};

static int n, m, map[1002][1002], dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
static bool visited[1002][1002][2];

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) map[i][j] = s[j] - '0';
    }

    if(n == 1 && m == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    queue<coor> q;
    q.push({0, 0, 0, 1});

    while(!q.empty())
    {
        coor here = q.front(); q.pop();

        for(int k = 0; k < 4; k++)
        {
            coor next = { here.x + dir[k][0], here.y + dir[k][1], here.broken, here.dist + 1 };
            if(next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;
            next.broken += map[next.x][next.y];

            if(next.broken > 1 || visited[next.x][next.y][next.broken]) continue;
            visited[next.x][next.y][next.broken] = true;

            if(next.x == n - 1 && next.y == m - 1)
            {
                cout << next.dist << '\n';
                return 0;
            }
            q.push(next);
        }
    }

    cout << -1 << '\n';
}