#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll cache[5002][5002], C[5002][5002], A[5002];
int N, K;

void dp(int n, int s1, int e1, int s2, int e2)
{
	if(s1 > e1)
		return;
	int mid = (s1 + e1) / 2, opt = 0;
	ll& ans = cache[n][mid];

	for(int k = s2; k < mid && k <= e2; k++)
	{
		ll result = cache[n - 1][k] + C[k + 1][mid];
		if(ans <= result)
		{
			ans = result;
			opt = k;
		}
	}

	dp(n, s1, mid - 1, s2, opt);
	dp(n, mid + 1, e1, opt, e2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> A[i];

	for(int i = 1; i <= N; i++)
	{
		for(int j = i; j <= N; j++)
			C[i][j] = C[i][j - 1] | A[j];
		cache[1][i] = C[1][i];
	}

	for(int i = 2; i <= K; i++)
	{
		dp(i, i, N, i - 1, N);
	}

	cout << cache[K][N] << '\n';
}