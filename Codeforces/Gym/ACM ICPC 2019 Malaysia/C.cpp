#include <iostream>
#include <algorithm>

using namespace std;

int d, n, s, f, t;

int main()
{
	cin >> d;
	for(int i = 1; i <= d; i++)
	{
		cout << "Case #" << i << ": ";

		cin >> n >> s;
		int ans = -1e9;
		for(int i = 0; i < n; i++)
		{
			cin >> f >> t;

			if(t <= s)
				ans = max(ans, f);
			else
				ans = max(ans, f - (t - s));
		}

		cout << ans << '\n';
	}
}