#include <iostream>

using namespace std;

int n, m, k, a, cnt[40];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(cin >> k; k > 0; k--)
		{
			cin >> a;
			cnt[a]++;
		}
	}

	int ans = 0;
	for(int i = 1; i <= m; i++)
		ans += (cnt[i] == n ? 1 : 0);

	cout << ans << '\n';

	return 0;
}