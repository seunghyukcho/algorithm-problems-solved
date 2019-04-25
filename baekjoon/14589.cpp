#include <iostream>
#include <algorithm>

using namespace std;

struct Line
{
	int idx, l, r;
} L[150002];

bool comp(Line l1, Line l2)
{
	return (l1.r > l2.r);
}

int N, Q;
int I[150002];
int cache[150002][20];

int dp(int n, int k)
{
	int &ret = cache[n][k];
	if(ret != -1)
		return ret;
	if(k == 0)
	{
		ret = n;
		for(int i = n + 1; i < N && L[i].l <= L[n].r; i++)
		{
			ret = (L[ret].r < L[i].r ? i : ret);
		}

		for(int i = n - 1; i >= 0; i--)
		{
			if(L[i].r >= L[n].l)
				ret = (L[ret].r < L[i].r ? i : ret);
		}

		return ret;
	}
	else
	{
		return ret = dp(dp(n, k - 1), k - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> L[i].l >> L[i].r;
		L[i].idx = i;
		for(int j = 0; j < 20; j++)
			cache[i][j] = -1;
	}
	sort(L, L + N, comp);
	for(int i = 0; i < N; i++)
		I[L[i].idx] = i;

	int start = 0, end = 0;
	for(; end < N; end++)
	{
		while(L[start].l > L[end].r)
			start++;

		cache[end][0] = start;
	}

	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		int start, end;
		cin >> start >> end;

		start--, end--;
		start = I[start], end = I[end];

		if(L[start].l > L[end].l)
			swap(start, end);

		if(L[end].l <= L[start].r)
			cout << 1 << '\n';
		else
		{
			int ans = 0;
			for(int j = 19; ans < N && j >= 0; j--)
			{
				int p = dp(start, j);
				
				if(L[p].r < L[end].l)
				{
					ans += (1 << j);
					start = p;
				}
			}

			if(ans >= N)
				cout << -1 << '\n';
			else
			{
				cout << ans + 2 << '\n';
			}
		}
	}
}
