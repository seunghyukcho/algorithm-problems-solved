#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int t, ans, n, arr[3000002];
deque<int> minDQ, maxDQ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int start = 1, end = 1, mx, mn;

	for(; end <= n; end++)
	{
		while(!minDQ.empty() && (arr[minDQ.back()] >= arr[end]))
			minDQ.pop_back();
		minDQ.push_back(end);

		while(!maxDQ.empty() && (arr[maxDQ.back()] <= arr[end]))
			maxDQ.pop_back();
		maxDQ.push_back(end);

		mx = arr[maxDQ.front()];
		mn = arr[minDQ.front()];

		while(mx - mn > t)
		{
			start++;
			while(minDQ.front() < start)
				minDQ.pop_front();
			while(maxDQ.front() < start)
				maxDQ.pop_front();

			mx = arr[maxDQ.front()];
			mn = arr[minDQ.front()];
		}

		ans = max(ans, end - start + 1);
	}

	cout << ans << '\n';
}