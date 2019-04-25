#include <iostream>

using namespace std;

int t, x, y;

int main()
{
	for(cin >> t; t > 0; t--)
	{
		cin >> x >> y;

		long long here = 1;
		int ans = 0;
		while(x < y)
		{
			x += here;
			ans += 1;

			if((here + 1) * (here + 2) / 2 <= y - x)
				here += 1;
			else if(here * (here + 1) / 2 > y - x)
				here -= 1;
		}

		cout << ans << '\n';
	}
}