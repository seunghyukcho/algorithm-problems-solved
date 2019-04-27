#include <iostream>
#include <algorithm>

using namespace std;

int C, N, M;
double cache[1002][1002];

double dp(int n, int m)
{
	if(n < 0)
		return 0;
	double &ret = cache[n][m];

	if(ret != -1)
		return ret;

	if(n > N + 1 || m == 0)
		return ret = 0;

	if(n < N)
		return ret = 0.75 * dp(n - 2, m - 1) + 0.25 * dp(n + 1, m - 1);
	else
		return ret = 0.75 * dp(n - 2, m - 1);
}

int main()
{
	for(cin >> C; C > 0; C--)
	{
		cin >> N >> M;

		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= M; j++)
				cache[i][j] = -1;

		cache[0][0] = 1;

		double ans = 0;
		for(int i = 0; i <= M; i++)
		{
			ans += dp(N, i);
		}

		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= M; j++)
				cout << i << ' ' << j << ' ' << dp(i, j) << '\n';
		cout << ans << '\n';
	}
}