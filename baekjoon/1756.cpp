#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int d, n, num, ans;
vector<int> v;
deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> d >> n;
	for(int i = 0; i < d; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for(int i = v.size() - 1; i >= 0; i--)
	{
		num = v[i];

		while(!dq.empty() && dq.back() > num)
			dq.pop_back();
		dq.push_back(num);
	}

	int j = v.size() - 1;
	for(int i = 0; i < n; i++)
	{
		cin >> num;

		while(j >= 0 && dq.front() < num)
		{
			if(v[j] == dq.front())
				dq.pop_front();
			j--;
		}

		ans = j;
		if(j >= 0)
		{
			if(v[j] == dq.front())
				dq.pop_front();
			j--;
		}
	}

	cout << ans + 1 << '\n';
}