#include <iostream>
#include <algorithm>

using namespace std;

int T, N, A[5002], B[5002];
int cache[5002][5002];

int dp(int l, int r)
{
	int& ret = cache[l][r];
	if(ret != -1)
		return ret;

	if(l == r)
		return ret = 0;
	if(l + 1 == r)
		return ret = (A[l] == B[r]) + (A[r] == B[l]) - (A[l] == B[l]) - (A[r] == B[r]);
	
	return ret = dp(l + 1, r - 1) + (A[l] == B[r]) + (A[r] == B[l]) - (A[l] == B[l]) - (A[r] == B[r]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int ans = 0;
		cout << "Case " << t << '\n';
		cin >> N;
		for(int i = 1; i <= N; i++)
			cin >> A[i];
		for(int i = 1; i <= N; i++)
			cin >> B[i];

		for(int i = 1; i <= N; i++)
		{
			ans += (A[i] == B[i] ? 1 : 0);
			for(int j = 1; j <= N; j++)
				cache[i][j] = -1;
		}

		int oans = ans;
		for(int i = 1; i < N; i++)
		{
			for(int j = i + 1; j <= N; j++)
			{
				ans = max(ans, oans + dp(i, j));
			}
		}

		cout << ans << '\n';
	}
}