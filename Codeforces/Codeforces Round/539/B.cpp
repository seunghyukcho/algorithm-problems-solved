#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[50002];
long long ans, total;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) 
	{
		cin >> a[i];
		total += a[i];
	}

	ans = total;
	sort(a, a + n);

	for(int i = 1; i < n; i++)
	{
		int here = a[i];
		for(int j = 2; j <= here; j++)
		{
			if(here % j == 0)
			{
				ans = min(ans, total - (here / j - a[0]) * (j - 1));
			}
		}
	}

	cout << ans << '\n';
	
}