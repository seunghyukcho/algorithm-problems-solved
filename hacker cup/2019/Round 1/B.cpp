#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <cstdlib>

#define MOD 1000000007;

using namespace std;

typedef long long ll;

int T, N, K, ssum[1000002];
string s;

ll pow(int n)
{
	if(n == 0) return 1;
	if(n == 1) return 2;

	ll ret = pow(n / 2);
	ret = ret * ret % MOD;

	if(n % 2 == 1)
		ret = ret * 2 % MOD;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		ll ans = 0, mn = 0;
		cout << "Case #" << t << ": ";
		cin >> N >> K >> s;

		reverse(s.begin(), s.end());
		
		for(int i = 1; i <= N; i++)
		{
			ssum[i] = ssum[i - 1] + (s[i - 1] == 'B' ? 1 : -1);
			
			if(ssum[i] - mn > K)
			{
				ans = (ans + pow(N - i + 1)) % MOD;
				ssum[i] -= 2;
			}

			if(ssum[i] < mn)
				mn = ssum[i];
		}

		cout << ans << '\n';
	}
}