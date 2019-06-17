#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, a[100002];

int main()
{
	int cnt[2] = {0, 0}, sum = 0, mn = 1e9;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		if(a[i] >= 0)
			cnt[0]++;
		else
			cnt[1]++;
		sum += abs(a[i]);
		mn = min(mn, abs(a[i]));
	}

	sort(a, a + n);
	if(cnt[0] * cnt[1] != 0)
	{
		cout << sum << '\n';

		int prev = a[0] - a[n - 1];

		if(a[1] >= 0)
			cout << a[0] << ' ' << a[n - 1] << '\n';
		else
		{
			prev *= -1;
			cout << a[n - 1] << ' ' << a[0] << '\n';
		}

		for(int i = 1; i < n - 2; i++)
		{
			if(a[i + 1] >= 0)
			{
				if(prev >= 0)
					cout << a[i] << ' ' << prev << '\n';
				else
					cout << prev << ' ' << a[i] << '\n';
				prev = -abs(prev) - abs(a[i]);
			}
			else
			{
				if(prev >= 0)
					cout << prev << ' ' << a[i] << '\n';
				else
					cout << a[i] << ' ' << prev << '\n';
				prev = abs(prev) + abs(a[i]);
			}
		}

		if(a[n - 2] - prev > prev - a[n - 2])
			cout << a[n - 2] << ' ' << prev << '\n';
		else
			cout << prev << ' ' << a[n - 2] << '\n';
	}
	else
	{
		cout << sum - 2 * mn << '\n';

		if(cnt[0] == 0)
		{
			int prev = a[n - 1] - a[n - 2];
			cout << a[n - 1] << ' ' << a[n - 2] << '\n';

			for(int i = n - 3; i > 0; i--)
			{
				cout << prev << ' ' << a[i] << '\n';
				prev = prev - a[i];
			}

			if(n > 2)
				cout << prev << ' ' << a[0] << '\n';
		}
		else
		{
			int prev = a[0] - a[1];
			cout << a[0] << ' ' << a[1] << '\n';

			for(int i = 2; i < n - 1; i++)
			{
				cout << prev << ' ' << a[i] << '\n';
				prev = prev - a[i];
			}

			if(n > 2)
				cout << a[n - 1] << ' ' << prev << '\n';
		}
	}

}