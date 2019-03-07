#include <iostream>
#include <algorithm>

using namespace std;

int n, v, w, k, ans;
int cache[100002];

int main()
{
	cin >> n >> k;
	for(int j = 1; j <= k; j++)
		cache[j] = -1;

	for(int i = 1; i <= n; i++)
	{
		cin >> w >> v;

		for(int j = k; j >= 0; j--)
		{
			int& here = cache[j];

			if(j - w >= 0 && cache[j - w] != -1)
			{
				here = max(here, cache[j - w] + v);
			}

			ans = max(ans, cache[j]);
		}
	}

	cout << ans << '\n';
}