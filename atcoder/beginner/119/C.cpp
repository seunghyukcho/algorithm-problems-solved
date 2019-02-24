#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int visited[10];
int ans, n, num[10], check[4];

int checkValue()
{
	int ret = 0;
	int cnt[4] = { 0, 0, 0, 0 };
	int arr[4] = { 0, 0, 0, 0 };
	for(int i = 0; i < n; i++)
	{
		arr[visited[i]] += num[i];
		cnt[visited[i]]++;
	}

	for(int i = 1; i < 4; i++)
	{
		if(arr[i] == 0) return 100000;
		ret += abs(arr[i] - check[i]) + 10 * (cnt[i] - 1);
	}

	return ret;
}

void dfs(int depth)
{
	if(depth == n)
	{
		int val = checkValue();
		
		ans = min(ans, val);
	}
	else
	{
		visited[depth] = 0;
		dfs(depth + 1);
		visited[depth] = 1;
		dfs(depth + 1);
		visited[depth] = 2;
		dfs(depth + 1);
		visited[depth] = 3;
		dfs(depth + 1);
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= 3; i++) cin >> check[i];
	for(int i = 0; i < n; i++) cin >> num[i];

	ans = 100000;
	dfs(0);
	cout << ans << '\n';
}