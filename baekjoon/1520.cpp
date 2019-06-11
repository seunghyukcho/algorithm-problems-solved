#include <iostream>
#include <algorithm>

using namespace std;

int n, m, map[502][502];
int cache[502][502], dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int dp(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	int& ret = cache[x][y];
	if(ret != -1)
		return ret;

	ret = 0;
	for(int k = 0; k < 4; k++)
	{
		int nextx = x + dir[k][0];
		int nexty = y + dir[k][1];

		if(map[x][y] < map[nextx][nexty])
			ret += dp(nextx, nexty);
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			cache[i][j] = -1;
		}

	cache[0][0] = 1;

	cout << dp(n - 1, m - 1) << '\n';
}