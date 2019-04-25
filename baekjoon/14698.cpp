#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int t, n;
priority_queue<ll> pq;
ll MOD = 1000000007;

ll mul(ll a, ll b)
{
	return ((a % MOD) * (b % MOD)) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(cin >> t; t > 0; t--)
	{
		ll ans = 1;
		if(!pq.empty())
			pq.pop();

		cin >> n;
		for(int i = 0; i < n; i++)
		{
			ll num;
			cin >> num;
			pq.push(-num);
		}

		while(pq.size() > 1)
		{
			ll first = -pq.top(); pq.pop();
			ll second = -pq.top(); pq.pop();

			ll newSlime = first * second;
			ans = mul(ans, newSlime);

			// cout << first << ' ' << second << ' ' << newSlime << ' ' << ans << '\n';

			pq.push(-newSlime);
		}

		cout << ans << '\n';
	}
}