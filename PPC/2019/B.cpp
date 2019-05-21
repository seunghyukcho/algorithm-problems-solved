#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int n;
ll mx[2], mn[2] = {INT_MAX, INT_MAX};

ll max(ll n1, ll n2)
{
	return n1 < n2 ? n2 : n1;
}

ll min(ll n1, ll n2)
{
	return n1 < n2 ? n1 : n2;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		mx[0] = max(mx[0], x - y);
		mx[1] = max(mx[1], x + y);
		mn[0] = min(mn[0], x - y);
		mn[1] = min(mn[1], x + y);
	}

	ll ans = max(mx[0] - mn[0], mx[1] - mn[1]);
	
	if(ans % 2)
	{
		ll k = ans / 2;
		cout << 2 * k * (k + 1) << ".5\n";
	}
	else
	{
		cout << ans / 2 * ans << '\n';
	}
}