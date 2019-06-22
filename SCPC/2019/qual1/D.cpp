#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ld;

int T, N;
pair<int, int> R[102];
double ans[102];

double distance(int r1, int r2)
{
	return 2 * sqrt(r1 * (double)r2);
}

bool comp(pair<int, int>& n1, pair<int, int>& n2)
{
	return n1.second > n2.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout.precision(10);
	cout << fixed;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << '\n';
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			cin >> R[i].second;
			R[i].first = i;
		}
		sort(R, R + N, comp);

		ans[R[0].first] = 0.0;
		int n = N;
		for(int i = 1; i < n; i++)
		{
			int idx1 = R[i - 1].first, idx2 = R[i].first;
			int r1 = R[i - 1].second, r2 = R[i].second;
			ans[idx2] = ans[idx1] + distance(r1, r2);

			double w = distance(r1, r2);
			double d1 = distance(r1, R[n - 1].second);
			double d2 = distance(r2, R[n - 1].second);
			
			if(i != n - 1 && d1 + d2 <= w)
				ans[R[n - 1].first] = ans[idx2] - distance(r2, R[n - 1].second);
		}

		for(int i = 0; i < N; i++)
			cout << ans[i] << '\n';
	}
}