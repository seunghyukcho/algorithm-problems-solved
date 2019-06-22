#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll cache1[1000002], cache2[1000002];
int T;
ll x, y;

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

ll max(ll a, ll b)
{
	return a < b ? b : a;
}

ll solve2(ll pos)
{
	ll& ret = cache2[pos];

	if(pos == 0)
		return 0;
	else if(pos == 1)
		return 1;
	else if(pos == 2)
		return 2;

	if(ret != 0)
		return ret;

	ll n = sqrt(2 * pos);
	ll sum = n * (n + 1) / 2;

	if(sum > pos)
	{
		n--;
		sum -= n + 1;
	}
	
	return ret = min(n + solve2(pos - sum), n - 1 + solve2(pos - sum + n));
}

ll solve1(ll pos)
{
	if(pos <= 1000000)
		return solve2(pos);

	ll n = sqrt(2 * pos);
	ll sum = n * (n + 1) / 2;

	if(sum > pos)
	{
		n--;
		sum -= n + 1;
	}

	return min(n + solve2(pos - sum), n - 1 + solve2(pos - sum + n));
}

ll solve4(ll start, ll end)
{
	ll ret = 0;
	ll n = sqrt(2 * end);
	ll sum = n * (n + 1) / 2;

	if(sum > y)
		sum -= n--;

	start = max(start, sum - n);

	for(; start <= end; start++)
		ret = max(ret, solve1(start));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << '\n';
		cin >> x >> y;
		
		cout << solve4(x, y) << '\n';
		setbuf(stdout, NULL);
	}
}