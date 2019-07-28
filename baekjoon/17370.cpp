#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int ans, n;
bool visited[400][400];

void dfs(int x, int y, int prevx, int prevy, int here)
{
    if(here == n) 
    {
        ans += (visited[x][y] ? 1 : 0);
        return;
    }
    else if(visited[x][y]) return;

    visited[x][y] = true;

    int nextx = x + 1, nexty = y;
    if(!(nextx == prevx && nexty == prevy)) dfs(nextx, nexty, x, y, here + 1);

    nextx = x - 1, nexty = y;
    if(!(nextx == prevx && nexty == prevy)) dfs(nextx, nexty, x, y, here + 1);

    nextx = x, nexty = ((x + y) % 2) ? y - 1 : y + 1;
    if(!(nextx == prevx && nexty == prevy)) dfs(nextx, nexty, x, y, here + 1);

    visited[x][y] = false;
}

int main()
{
    cin >> n;

    visited[200][200] = true;
    dfs(200, 201, 200, 200, 0);

    cout << ans << '\n';
}