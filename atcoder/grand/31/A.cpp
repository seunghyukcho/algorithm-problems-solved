#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

long long ans;
int cnt[30], n;
string s;

void dfs(int here, long long ansHere)
{
	if(here == 'z' - 'a' + 1)
	{
		ans = (ans + ansHere) % MOD;
		return;
	}

	dfs(here + 1, ansHere);
	if(cnt[here] > 0)
		dfs(here + 1, (ansHere * cnt[here]) % MOD);

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cnt[s[i] - 'a']++;

	dfs(0, 1);

	cout << ans - 1 << '\n';
}