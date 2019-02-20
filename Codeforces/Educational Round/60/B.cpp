#include <iostream>

using namespace std;

int n, m, k;
long long ans, mx, smx;

int main()
{
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if(mx <= num)
		{
			smx = mx;
			mx = num;
		}
		else if(smx <= num)
		{
			smx = num;
		}
	}

	ans += (mx * k + smx) * (m / (k + 1));
	m %= k + 1;

	ans += mx * m;

	cout << ans << '\n';

	return 0;
}