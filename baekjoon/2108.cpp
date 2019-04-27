#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int arr[500002], cnt[8002], N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool flag = false;
	int mn = 4001, mx = -4001, cntMX = -4000;
	ll sum = 0;

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];

		cnt[arr[i] + 4000]++;
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
		sum += arr[i];
	}

	for(int i = -4000; i <= 4000; i++)
	{
		if(cnt[cntMX + 4000] < cnt[i + 4000])
		{
			cntMX = i;
			flag = false;
		}
		else if(cnt[cntMX + 4000] == cnt[i + 4000])
		{
			if(!flag)
				cntMX = i;
			flag = true;
		}
	}

	sort(arr, arr + N);

	cout << round(sum * 1.0 / N) << '\n';
	cout << arr[N / 2] << '\n';
	cout << cntMX << '\n';
	cout << mx - mn << '\n';
}