#include <iostream>
#include <algorithm>

using namespace std;

int t, n, arr[1002];
pair<int, int> cache[1002][1002];
int nxt[1002][1002];

pair<int, int> dp(int idx, int sum)
{
	if(idx == n || sum == 0)
		return { 0, 0 };

	auto& ret = cache[idx][sum];
	if(ret.first != -1)
		return ret;

	for(int i = idx + 1; i < n; i++)
	{
		if(arr[i] <= sum)
		{
			auto result = dp(i, sum - arr[i]);
			if(result.first == -1)
				continue;

			result.first += arr[i];
			if(result.first > ret.first)
			{
				ret = result;
				nxt[idx][sum] = i;
			}

			else if(result.first == ret.first && result.second < ret.second)
			{
				ret = result;
				nxt[idx][sum] = i;
			}
		}
	}

	ret.second += 1;
	return ret;
}

int main()
{
	while(1)
	{
		cin >> t;
		if(t == 0) break;

		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			for(int j = 0; j < 1002; j++)
			{
				cache[i][j] = { -1, 1 };
				nxt[i][j] = -1;
			}
		}

		pair<int, int> ans = { 0, 0 };
		int startIdx;
		for(int i = 0; i < n; i++)
			if(arr[i] <= t)
			{
				auto result = dp(0, t - arr[i]);
				if(result.first > ans.first)
				{
					ans = result;
					startIdx = i;
				}

				else if(result.first == ans.first && result.second < ans.second)
				{
					ans = result;
					startIdx = i;
				}
			}

		for(int here = startIdx; here != -1; t -= arr[here])
		{
			cout << arr[here] << ' ';
			here = nxt[here][t];
		}

		cout << ans.first << '\n';
	}
}