#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

ll ans, mx = -1e9, mn = 1e9;
priority_queue<ll> pq;
int N;

int main()
{
	int num;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(-num);
		mx = mx < num ? num : mx;
		if(num > 0)
			mn = mn > num ? num : mn;	
	}

	if(mx <= 0)
	{
		for(int i = 0; i < N; i++)
		{
			int here = pq.top(); pq.pop();
			pq.push(-here);

			mx = mx < here ? here : mx;
		}
	}

	while(pq.top() > 0)
	{
		int here = pq.top(); pq.pop();
		int next = mn - here % mn;
		pq.push(-next);
		mx = mx < next ? next : mx;
	}

	ans = mx + pq.top();

	while(N > 1)
	{
		ll n1 = -pq.top(); pq.pop();
		ll n2 = -pq.top();

		ll n3 = n1 + n2; pq.push(-n3);
		if(mx <= n3)
		{
			ans = ans < n1 ? ans : n1;
			break;
		}

		ans = ans < mx - n2 ? ans : mx - n2;
	}

	cout << ans << '\n';
}
