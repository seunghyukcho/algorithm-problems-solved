#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int a, b, q;
ll s[100002], t[100002], x;

ll binary1(int start, int end, ll find, ll arr[])
{
	while(start + 1 < end)
	{
		int mid = (start + end) / 2;
		ll val = arr[mid];

		if(val > find) end = mid - 1;
		else start = mid;
	}

	if(arr[end] <= find) return end;
	else return start;
}

ll binary2(int start, int end, ll find, ll arr[])
{
	while(start < end)
	{
		int mid = (start + end) / 2;
		ll val = arr[mid];

		if(val < find) start = mid + 1;
		else end = mid;
	}

	return end;
}

ll min(ll l1, ll l2)
{
	return l1 < l2 ? l1 : l2;
}

ll max(ll l1, ll l2)
{
	return l1 < l2 ? l2 : l1;
}

int main()
{
	cin.tie(NULL);

	cin >> a >> b >> q;
	for(int i = 0; i < a; i++) cin >> s[i];
	for(int i = 0; i < b; i++) cin >> t[i];

	for(int i = 0; i < q; i++)
	{
		ll ans;
		cin >> x;

		ll sl = s[binary1(0, a - 1, x, s)], sr = s[binary2(0, a - 1, x, s)];
		ll tl = t[binary1(0, b - 1, x, t)], tr = t[binary2(0, b - 1, x, t)];

		ans = abs(sl - x) + abs(sl - tr);
		ans = min(ans, abs(tr - x) + abs(sl - tr));
		ans = min(ans, abs(sr - x) + abs(sr - tl));
		ans = min(ans, abs(tl - x) + abs(sr - tl));
		
		if(sl <= x && tl <= x)
		{
			ans = min(ans, abs(min(sl, tl) - x));
		}

		if(x <= sr && x <= tr)
		{
			ans = min(ans, abs(max(sr, tr) - x));
		}

		cout << ans << '\n';
	}
}