#include <iostream>

using namespace std;

int T, N, arr[102];
int cache[102][102][102];
int oneIdx;

bool solve(int s, int t, int k)
{
	int& ret = cache[s][t][k];
	if(ret != -1)
		return ret;

	if(s == t)
		return ret = 1;
	if(k > 0 && !solve(s, t, k - 1))
		return ret = 1;
	if(arr[s] != 1 && arr[s] > arr[s + 1] && !solve(s + 1, t, k))
		return ret = 1;
	if(arr[t] != 1 && arr[t - 1] < arr[t] && !solve(s, t - 1, k))
		return ret = 1;

	for(int i = s + 1; i < t; i++)
	{
		if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
		{
			if(oneIdx < i && !solve(s, i - 1, k + t - i))
				return ret = 1;
			else if(oneIdx > i && !solve(i + 1, t, k + i - s))
				return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(cin >> T; T > 0; T--)
	{
		cin >> N;
		for(int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			if(arr[i] == 1) oneIdx = i;
			for(int j = i; j <= N; j++)
				for(int k = 0; k <= N; k++)
					cache[i][j][k] = -1;
		}

		cout << (solve(1, N, 0) ? "Alice" : "Bob") << '\n';
	}
}