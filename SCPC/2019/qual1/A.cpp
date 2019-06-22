#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int cache[1000002];
int T, n1, n2;
ll sum[1000002];

int dp(int n)
{
	int& ret = cache[n];

	if(ret != -1)
		return ret;
	if(n % 2 == 1)
		return ret = 1 + dp(n + 1);
	else
		return ret = 1 + dp(n / 2);
}

int main()
{
	for(int i = 1; i <= 1000000; i++)
		cache[i] = -1;
	cache[1] = 0;

	for(int i = 1; i <= 1000000; i++)
		sum[i] = dp(i) + sum[i - 1];

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << '\n';

		cin >> n1 >> n2;
		cout << sum[n2] - sum[n1 - 1] << '\n';
	}
}