#include <iostream>
#include <algorithm>

using namespace std;

int t, n, arr[1002];
pair<int, int> cache[1002][1002];
int nxt[1002][1002];

pair<int, int> dp(int idx, int sum)
{
	if(idx == n)
		return { 0, 0 };

	auto& ret = cache[idx][sum];
	if(ret.first != -1)
		return ret;

	for(int i = idx + 1; i <= n; i++)
	{
		if(arr[i] <= sum - arr[idx])
		{
			auto result = dp(i, sum - arr[idx]);
			result.first += arr[idx];

			if(result.first > ret.first)
			{
				ret = result;
				nxt[idx][sum] = i;
			}

			else if(result.first == ret.first && result.second > ret.second)
			{
				ret = result;
				nxt[idx][sum] = i;
			}
		}
	}

	ret.second += 1;

	// cout << idx << ' ' << sum << ' ' << ret.first << ' ' << ret.second << ' ' << nxt[idx][sum] << '\n';

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
				cache[i][j] = { -1, -1 };
				nxt[i][j] = -1;
			}
		}
		arr[n] = 0;

		pair<int, int> ans = { -1, 0 };
		int startIdx;
		for(int i = 0; i < n; i++)
		{
			if(arr[i] <= t)
			{
				auto result = dp(i, t);
				if(result.first > ans.first)
				{
					ans = result;
					startIdx = i;
				}

				else if(result.first == ans.first && result.second > ans.second)
				{
					ans = result;
					startIdx = i;
				}
			}
		}
		
		for(int here = startIdx; here != n;)
		{
			cout << arr[here] << ' ';

			int prev = here;
			here = nxt[here][t];
			t -= arr[prev];
		}
		

		cout << ans.first << '\n';
	}
}