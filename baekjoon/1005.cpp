#include <iostream>
#include <vector>

using namespace std;

int n, t, k, w;
int cache[1002], build[1002];
vector<int> graph[1002];

int dp(int here)
{
	int &ret = cache[here];

	if(ret != -1)
		return ret;

	ret = 0;
	for(int next : graph[here])
		ret = max(ret, dp(next));

	return ret = ret + build[here];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(cin >> t; t > 0; t--)
	{
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			cin >> build[i];
			graph[i].clear();
			cache[i] = -1;
		}
		for(int i = 0; i < k; i++)
		{
			int s, e;
			cin >> s >> e;
			graph[e - 1].push_back(s - 1);
		}

		cin >> w;
		cout << dp(w - 1) << '\n';
	}
}