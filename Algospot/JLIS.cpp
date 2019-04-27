#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int t, n, m;
int a[102], b[102];
int cache[102][102];

int dp(int x, int y)
{
	int &ret = cache[x][y];

	if(ret != -1)
		return ret;

	ret = 0;
	
	if(a[x] > b[y])
	{
		for(int i = 0; i < x; i++)
		{
			if(a[i] < a[x] && (y == 0 || a[i] != b[y]))
				ret = max(ret, dp(i, y) + 1);
		}
	}
	else if(a[x] < b[y])
	{
		for(int i = 0; i < y; i++)
		{
			if(b[i] < b[y] && (x == 0 || b[i] != a[x]))
				ret = max(ret, dp(x, i) + 1);
		}
	}

	return ret;
	
}

int main()
{
	a[0] = b[0] = INT_MIN;

	for(cin >> t; t > 0; t--)
	{
		int ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];

			for(int j = 0; j <= m; j++)
				cache[i][j] = -1;
		}
		for(int i = 1; i <= m; i++)
		{
			cache[0][i] = -1;
			cin >> b[i];
		}
		

		cache[0][0] = 0;

		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= m; j++)
			{
				if(a[i] != b[j])
					ans = max(ans, dp(i, j));
			}
		}

		cout << ans << '\n';
	}
}