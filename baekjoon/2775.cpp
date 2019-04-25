#include <iostream>

using namespace std;

int cache[15][15];

int dp(int n, int k)
{
	int &ret = cache[n][k];
	if(ret != -1)
		return ret;

	if(n == 0)
		return ret = k;
	ret = 0;
	for(int i = 1; i <= k; i++)
		ret += dp(n - 1, i);
	return ret;
}

int main()
{
	int t, n, k;
	for(int i = 0; i < 15; i++)
		for(int j = 0; j < 15; j++)
			cache[i][j] = -1;
	
	for(cin >> t; t > 0; t--)
	{
		cin >> k >> n;

		cout << dp(k, n) << '\n';
	}
}