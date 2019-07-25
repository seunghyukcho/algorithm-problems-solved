#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

typedef long long ll;

int n, K, e;
int cache[2002][1024];
bool invalid[2002][2002];

int main()
{
	cin >> n >> e >> K;
	for(int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		invalid[a][b] = true;
	}

	cache[1][0] = 1;

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < (1 << (2 * e + 1)); j++)
		{
			if(cache[i][j] == 0)
				continue;

			for(int k = 0; k < 2 * e + 1; k++)
			{
				if(i + k - e < 1 || i + k - e > n || ((1 << k) & j) != 0 || invalid[i][i + k - e])
					continue;

				int state = (j + (1 << k)) >> 1;

				cache[i + 1][state] += cache[i][j];
				cache[i + 1][state] %= MOD;
			}
		}
	}

	ll ans = 0;
	for(int j = 0; j < (1 << (2 * e + 1)); j++)
	{
		if(cache[n][j] == 0)
			continue;
		int cnt = 0;
		for(int k = 0; k < 2 * e + 1; k++)
		{
			if(n + k - e < 1 || n + k - e > n || ((1 << k) & j) != 0 || invalid[n][n + k - e])
				continue;
			cnt++;
		}

		ans = (ans + (cache[n][j] * (ll)cnt) % MOD) % MOD;
	}

	cout << ans << '\n';
}