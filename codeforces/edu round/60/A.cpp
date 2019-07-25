#include <iostream>
#include <algorithm>

using namespace std;

int n, ans[2], a[100002];

int main()
{
	int here = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		if(i == 0 || a[i - 1] != a[i])
		{
			if(ans[0] < a[i - 1])
			{
				ans[0] = a[i - 1];
				ans[1] = here;
			}
			else if(ans[0] == a[i - 1])
			{
				ans[1] = max(ans[1], here);
			}

			here = 1;
		}
		else
			here++;
	}

	if(ans[0] < a[n - 1])
	{
		ans[0] = a[n - 1];
		ans[1] = here;
	}
	else if(ans[0] == a[n - 1])
	{
		ans[1] = max(ans[1], here);
	}

	cout << ans[1] << '\n';
}