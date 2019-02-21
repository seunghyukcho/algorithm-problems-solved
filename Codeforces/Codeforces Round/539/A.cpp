#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, v, ans, here;
	cin >> n >> v;

	here = min(v, n - 1);
	ans = here;
	here--;
	for(int i = 2; i < n; i++)
	{
		if(here < n - i)
		{
			int left = min(n - i - here, v - here);
			ans += i * left;

			here += left;
		}

		here--;
	}

	cout << ans << '\n';
}