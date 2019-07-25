#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[100002], ans;

int main()
{
	cin >> m;
	for(int t = 1; t <= m; t++)
	{
		cout << "Case #" << t << ": ";
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);

		long long sum = 0;
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(sum <= arr[i])
			{
				sum += arr[i];
				ans++;
			}
		}

		cout << ans << '\n';
	}
}