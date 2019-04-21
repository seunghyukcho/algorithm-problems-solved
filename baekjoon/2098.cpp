#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[20][20], N;
int cache[20][1 << 17];

int dp(int start, int here, int left)
{
	int& ret = cache[here][left];

	if(ret != -1)
		return ret;
	if(left == 0)
		return ret = 0;

	for(int i = 0; i < N; i++)
	{
		int check = left & (1 << i);

		if(check && graph[here][i] != 0)
		{
			if(i == start && left - (1 << start) != 0)
				continue;

			int result = dp(start, i, left - (1 << i)) + graph[here][i];
			if(result == -1)
				continue;

			ret = (ret == -1 ? result : min(ret, result));
		}
	}

	return ret;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < (1 << N); j++)
			cache[i][j] = -1;

		for(int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}


	int ans = 1e9;
	for(int i = 0; i < N; i++)
	{
		ans = min(ans, dp(i, i, (1 << N) - 1));
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < (1 << N); j++)
			cout << i << ' ' << j << ' ' << cache[i][j] << '\n';
	}

	cout << ans << '\n';
}