#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int n, k;
vector<int> v;

int main()
{
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}

	while(1)
	{
		int cnt = 0, pivot = rand() % v.size();
		vector<int> next1, next2;

		for(int num : v)
		{
			if(num < v[pivot])
				next1.push_back(num);
			else if(num == v[pivot])
				cnt++;
			else
				next2.push_back(num);
		}

		if(next1.size() >= k)
			v = next1;
		else if(k <= next1.size() + cnt)
		{
			cout << v[pivot] << '\n';
			break;
		}
		else
		{
			v = next2;
			k -= next1.size() + cnt;
		}
	}
}