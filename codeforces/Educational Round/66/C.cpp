#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int t, n, k, a[200002];

int main()
{
	for(cin >> t; t > 0; t--)
	{
		int ans[2] = {INT_MAX, INT_MAX};

		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> a[i];

		for(int i = 0; i + k < n; i++)
		{
			int idx1 = i, idx2 = i + k;
			int mid = (a[idx1] + a[idx2]) / 2;

			// cout << idx1 << ' ' << idx2 << ' ' << mid << '\n';

			if(ans[0] > max(a[idx2] - mid, mid - a[idx1]))
			{
				ans[0] = max(a[idx2] - mid, mid - a[idx1]);
				ans[1] = mid;
			}
		}

		cout << ans[1] << '\n';
	}
}