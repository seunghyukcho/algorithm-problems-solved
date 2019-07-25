#include <iostream>

using namespace std;

typedef long long ll;

int t;
ll n, k;

int main()
{
	for(cin >> t; t > 0; t--)
	{
		cin >> n >> k;

		ll ans = 0;

		while(n > 0)
		{
			ans += n % k;
			if(n - n % k > 0)
			{
				ans += 1;
			}
			n /= k;
		}

		cout << ans << '\n';
	}
}