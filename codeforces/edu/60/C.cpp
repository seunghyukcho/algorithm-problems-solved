#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

typedef long long ll;

using namespace std;

ll abs(ll l1, ll l2)
{
	return l1 > l2 ? l1 - l2 : l2 - l1;
}

int main()
{
	ll x1, x2, y1, y2;
	ll dx = 0, dy = 0;
	string s;
	ll n;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> n;
	cin >> s;
	
	for(char ch : s)
	{
		switch(ch)
		{
			case 'L':
				dx--;
				break;
			case 'R':
				dx++;
				break;
			case 'U':
				dy++;
				break;
			case 'D':
				dy--;
				break;
		}
	}
	
	ll start = 1, end = 1e15;

	while(start < end)
	{
		ll mid = (start + end) / 2;
		// cout << start << ' ' << end << ' ' << mid << '\n';
		ll q = (mid - mid % n) / n, r = mid % n;
		// cout << q << ' ' << r << '\n';
		ll herex = x1, herey = y1;
		
		herex += dx * q, herey += dy * q;
		for(int i = 0; i < r; i++)
		{
			switch(s[i])
			{
				case 'L':
					herex--;
					break;
				case 'R':
					herex++;
					break;
				case 'U':
					herey++;
					break;
				case 'D':
					herey--;
					break;
			}
		}
		
		// cout << herex << ' ' << herey << "\n\n";
		if(abs(herex - x2) + abs(herey - y2) <= mid)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	
	ll ans = end;
	if(ans == 1e15)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
		
	return 0;
}
