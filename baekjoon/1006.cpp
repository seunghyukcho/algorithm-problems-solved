#include <iostream>

using namespace std;

int t, n, w;
int cache[10002][10002];
int data[2][10002];
bool visited[2];

int dp(int col1, int col2)
{
	int& ret = cache[col1][col2];

	if(ret != -1)
		return ret;

	ret = 1e9;

	if(col1 == col2)
	{
		if(col1 == 1)
		{
			if(!visited[0])
				ret = min(ret, dp(col1 - 1, col2));
			if(!visited[1])
				ret = min(ret, dp(col1, col2 - 1));
			if(!visited[0] && !visited[1] && data[0][1] + data[1][1] <= w)
				ret = min(ret, dp(col1 - 1, col2 - 1));
		}
		else
		{
			ret = min(dp(col1 - 1, col2), dp(col1, col2 - 1));
			if((col1 != 2 || (!visited[0] && !visited[1])) && data[0][col1] + data[0][col1 - 1] <= w && data[1][col2] + data[1][col2 - 1] <= w)
				ret = min(ret, dp(col1 - 2, col2 - 2) + 1);

			if(data[0][col1] + data[1][col2] <= w)
				ret = min(ret, dp(col1 - 1, col2 - 1));
		}
	}
	else if(col1 + 1 == col2)
	{
		if(col2 >= 2 && (col2 != 2 || !visited[1]) && data[1][col2] + data[1][col2 - 1] <= w)
			ret = min(ret, dp(col1, col2 - 2));
		ret = min(ret, dp(col1, col2 - 1));
	}
	else
	{
		if(col1 >= 2 && (col1 != 2 || !visited[0]) && data[0][col1] + data[0][col1 - 1] <= w)
			ret = min(ret, dp(col1 - 2, col2));
		ret = min(ret, dp(col1 - 1, col2));
	}

	return ret = ret + 1;
}

void initialize()
{
	visited[0] = visited[1] = false;
	for(int i = 1; i <= n; i++)
		cache[i][i - 1] = cache[i][i] = cache[i][i + 1] = -1;
	cache[0][1] = cache[0][0] = -1;
}

void output()
{
	for(int i = 0; i <= n; i++)
		for(int j = max(0, i - 1); j <= min(n, i + 1); j++)
			cout << i << ' ' << j << ' ' << cache[i][j] << '\n';
}

int main()
{
	for(cin >> t; t > 0; t--)
	{
		cin >> n >> w;
		for(int i = 1; i <= n; i++)
			cin >> data[0][i];
		for(int i = 1; i <= n; i++)
			cin >> data[1][i];

		initialize();
		cache[0][0] = 0;

		int ans = dp(n, n);

		if(n > 1 && data[0][1] + data[0][n] <= w)
		{
			initialize();
			cache[1][0] = 1;
			visited[0] = true;
			ans = min(ans, dp(n - 1, n));
		}

		if(n > 1 && data[1][1] + data[1][n] <= w)
		{
			initialize();
			cache[0][1] = 1;
			visited[1] = true;
			ans = min(ans, dp(n, n - 1));
			
			if(data[0][1] + data[0][n] <= w)
			{
				initialize();
				cache[1][1] = 2;
				visited[0] = visited[1] = true;
				ans = min(ans, dp(n - 1, n - 1));
			}
		}
		cout << ans << '\n';
	}
}