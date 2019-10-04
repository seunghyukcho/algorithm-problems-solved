#include <iostream>
#include <algorithm>

using namespace std;

int n, cache[5001][5001], arr[10001][2];

int dp(int i, int j)
{
    if(i < 0 || j < 0) return 1e9;

    int& ret = cache[i][j];
    if(ret != -1) return ret;

    if(i == j) return ret = dp(i - 1, j) + arr[i + j][0];
    else return ret = min(dp(i - 1, j) + arr[i + j][0], dp(i, j - 1) + arr[i + j][1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];
    for(int i = 0; i <= n / 2; i++)
    {
        for(int j = 0; j <= n / 2; j++) cache[i][j] = -1;
    }

    cache[0][0] = 0;
    cout << dp(n / 2, n / 2) << '\n';
}