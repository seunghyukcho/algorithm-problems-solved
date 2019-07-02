#include <iostream>

using namespace std;

int T, n, m, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		cin >> n >> m >> k;
		if(n < m)
			swap(n, m);

		int ans = 1e9, result1 = (n - 1) / k + 1, result2 = (m - 1) / k + 1, result3 = (k == 1 ? 5 : 4);

		if(n > k && 2 * k + 1 < m - 1)
			ans = min(ans, result1);
		if(m > k && 2 * k + 1 < n - 1)
			ans = min(ans, result2);
		if((k == 1 && n > 4 && m > 3) || (k != 1 && n > 3 * k && m > 2 * k + 1))
			ans = min(ans, result3);

		cout << (ans != 1e9 ? ans : -1) << '\n';
	}

}