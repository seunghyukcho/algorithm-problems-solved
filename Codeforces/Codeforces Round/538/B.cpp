#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
long long sum;
pair<int, int> a[200002];

int main()
{
	vector<int> idx;

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		a[i].second = i;
		cin >> a[i].first;
	}

	sort(a + 1, a + n + 1);
	for(int i = n; i >= n - m * k + 1; i--)
	{
		sum += a[i].first;
		idx.push_back(a[i].second);
	}

	sort(idx.begin(), idx.end());
	printf("%lld\n", sum);

	for(int i = 1; i <= k - 1; i++)
		printf("%d ", idx[i * m - 1]);

	printf("\n");
	return 0;
}