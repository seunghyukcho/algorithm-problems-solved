#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll bino[202][202];
int c, n, m, k;

ll binomial(int a, int b)
{
	ll& ret = bino[a][b];

	if(ret)
		return ret;
	else if(a == b || b == 0)
		return ret = 1;
	else
		return ret = binomial(a - 1, b - 1) + binomial(a - 1, b);
}

void dp(int a, int b, int skip, string& ans)
{
	ll left = binomial(a + b - 1, a - 1);
	// cout << ans << ' ' << skip << ' ' << left << '\n';
	if(a == 0 && b == 0)
		return;

	if(a > 0 && skip <= left)
	{
		ans += '-';
		dp(a - 1, b, skip, ans);
	}
	else
	{
		ans += 'o';
		dp(a, b - 1, skip - left, ans);
	}
}

int main()
{
	for(cin >> c; c > 0; c--)
	{
		cin >> n >> m >> k;
		string ans = "";

		dp(n, m, k, ans);
		cout << ans << '\n';
	}
}