#include <iostream>

using namespace std;

typedef long long ll;

int n, m, num;

int main()
{
	cin >> n >> m;

	ll totalSum = 0;
	for(int i = 0; i < n; i++)
	{
		ll sum = 0;
		for(int j = 0; j < m; j++)
		{
			cin >> num;
			sum += num;
		}

		totalSum ^= sum;
	}

	cout << (totalSum != 0 ? "august14" : "ainta") << '\n';
}