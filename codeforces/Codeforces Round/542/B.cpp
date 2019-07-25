#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int, int> a[200002];
int n;
long long ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n * 2; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + n * 2 + 1);
	a[0].second = 1;

	ans = abs(a[1].second - 1) + abs(a[2].second - 1);

	for(int i = 1; i <= n * 2 - 2; i += 2)
	{
		int a1 = a[i].second;
		int a2 = a[i + 1].second;
		int a3 = a[i + 2].second;
		int a4 = a[i + 3].second;

		long long here = min(abs(a1 - a3) + abs(a2 - a4), abs(a1 - a4) + abs(a2 - a3));
		ans += here;
	}

	cout << ans << '\n';
}