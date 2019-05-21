#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, c[200002], d[200002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n; i++)
		cin >> d[i];

	sort(c, c + n);
	sort(d, d + n);

	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
		ans = min(ans, c[i] + d[n - i - 1]);

	cout << ans << '\n';
}