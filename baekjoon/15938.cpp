#include <iostream>
#include <cmath>
#include <vector>
#define MOD 1000000007

using namespace std;

int xs, ys, xh, yh, n;
int cache[401][401][202], T;
int map[401][401], dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };

bool outside(int x, int y)
{
    return x < 0 || y < 0 || x > 2 * T || y > 2 * T;
}

int dp(int x, int y, int t)
{
    int& ret = cache[x][y][t];
    if(ret != -1) return ret;
    if(t == 0) return ret = 0;

    ret = 0;
    for(int k = 0; k < 4; k++)
    {
        int nextx = x + dir[k][0], nexty = y + dir[k][1];
        if(!outside(nextx, nexty) && !(nextx == xh && nexty == yh))
            ret = (ret + dp(nextx, nexty, t - 1)) % MOD;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   
    cin >> xs >> ys >> T >> xh >> yh >> n;

    if(abs(xs - xh) + abs(ys - yh) > T)
    {
        cout << 0 << '\n';
        return 0;
    }

    xh = xh - xs + T, yh = yh - ys + T;
    for(int i = 0; i <= 2 * T; i++)
        for(int j = 0; j <= 2 * T; j++)
            for(int k = 0; k <= T; k++) cache[i][j][k] = -1;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        x = x - xs + T, y = y - ys + T;
        if(!outside(x, y))
            for(int j = 0; j <= T; j++) cache[x][y][j] = 0;
    }

    xs = T, ys = T;
    cache[xs][ys][0] = 1;

    int ans = 0;
    for(int i = 0; i <= T; i++) ans = (ans + dp(xh, yh, i)) % MOD;
    
    cout << ans << '\n';
}