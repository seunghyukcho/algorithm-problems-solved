#include <iostream>
#include <algorithm>

using namespace std;

struct Line
{
	int l, r;
} L[2000002];

bool comp(Line l1, Line l2)
{
	return (l1.r > l2.r);
}

int N, Q;
int I[2000002];
int cache[2000002][30];

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

	cin >> N >> Q;
	for(int i = 0; i < N; i++)
	{
		cin >> L[i].l >> L[i].r;
		L[i].idx = i;
		for(int j = 0; j < 20; j++)
			cache[i][j] = -1;
	}
	sort(L, L + N, comp);

	int start = 0, end = 0;
	for(; end < N; end++)
	{
		while(L[start].l > L[end].r)
			start++;

		cache[end][0] = start;
	}

	for(int i = 0; i < Q; i++)
	{
		int start, end;
		cin >> start >> end;

		int idx = 0;
		while(1)
		{
			int last = dp(idx, 29);

			if(L[i].r >= start)
				break;
			idx = last + 1;
		}


	}
}
