#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int M, N, ans;
deque<int> dq;

int main()
{
	cin >> M >> N;

	for(int i = 1; i <= M; i++)
		dq.push_back(i);

	for(int i = 0; i < N; i++)
	{
		int num, cnt = 0;
		cin >> num;

		while(dq.front() != num)
		{
			cnt++;
			dq.push_back(dq.front());
			dq.pop_front();
		}


		ans += min(cnt, (int)dq.size() - cnt);
		dq.pop_front();
	}

	cout << ans << '\n';
}