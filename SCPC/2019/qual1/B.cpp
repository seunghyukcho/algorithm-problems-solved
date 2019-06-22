#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

using namespace std;

int T, R, S, E, N;

int main()
{
	cout.precision(8);
	cout << fixed;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		double ans = 0.0;
		int l, r, h, w, here;

		cin >> R >> S >> E >> N;

		here = S;
		for(int i = 0; i < N; i++)
		{
			cin >> l >> r >> h;
			w = r - l;

			ans += l - here - R;
			here = r + R;

			if(h - R > 0)
				ans += 2 * (h - R) + w + M_PI * R;
			else
			{
				double k = sqrt(R * R - (R - h) * (R - h));
				double theta = asin(k / R);

				// cout << k << ' ' << theta << '\n';

				ans += w + 2 * R * theta;
				ans += 2 * (R - k);
			}
		}

		ans += E - here;

		cout << "Case #" << t << '\n';
		cout << ans << '\n';
	}
}