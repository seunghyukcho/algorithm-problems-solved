#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	for(;;)
	{
		cin >> n >> k;
		if(n == 0 && k == 0)
			break;

		if(k > n / 2)
			k = n - k;

		long long ans = 1;
		for(int i = 1; i <= k; i++)
		{
			ans = ans * (n - k + i) / i;
		}

		cout << ans << '\n';
	}
}