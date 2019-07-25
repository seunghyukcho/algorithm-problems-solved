#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int xr[300002], a[300002], n;
map<int, pair<int, int> > m;
long long ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		xr[i] = xr[i - 1] ^ a[i];
	}

	for(int i = 1; i <= n; i++)
	{
		int f = xr[i];
		auto it = m.find(f);
		if(it != m.end())
		{
			int result = i % 2 ? m[f].first : m[f].second;
			ans += result;
		}

		if(i % 2 == 0 && xr[i] == 0)
			ans++;

		i % 2 ? m[xr[i]].first++ : m[xr[i]].second++;
	}

	cout << ans << '\n';

}