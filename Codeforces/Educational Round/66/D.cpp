#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int n, k;
ll a[300002];

int main()
{
	int cnt = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	priority_queue<ll> pq;
	pq.push(a[n]);
	for(int i = n - 1; i >= 1; i--)
	{
		a[i] += a[i + 1];
		if(i != 1)
			pq.push(a[i]);
	}

	ll ans = a[1];
	for(int i = 0; i < k - 1; i++)
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans << '\n';
}