#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, cache[1000002];
string s;

int dp(int here, vector<int> &pi)
{
	int &ret = cache[here];
	if(ret != -1)
		return ret;

	if(pi[here] == 0)
		return ret = 0;

	ret = pi[here];
	while(dp(ret - 1, pi) > 0)
		ret = dp(ret - 1, pi);

	return ret;
}

void FailureFunction(vector<int> &v)
{
	v = vector<int>(n + 1, 0);

	int j = 0;
	for(int i = 1; i < s.size(); i++)
	{
		while(j > 0 && s[i] != s[j]) 
			j = v[j - 1];

		if(s[i] == s[j])
			v[i] = ++j;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> pi;

	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cache[i] = -1;

	FailureFunction(pi);

	long long ans = 0;

	for(int i = 1; i < s.size(); i++)
	{
		if(dp(i, pi) == 0)
			continue;
		ans += i + 1 - dp(i, pi);
		// cout << dp(i, pi) << ' ' << pi[i] << '\n';
	}

	cout << ans << '\n';
}