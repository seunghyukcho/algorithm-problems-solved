#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n;
vector<int> primes;

void generatePrimes()
{
	vector<bool> visited(100002, false);

	for(int i = 2; i <= 100000; i++)
	{
		if(!visited[i])
		{
			primes.push_back(i);

			for(long long j = (long long)i * i; j <= 100000; j += i)
				visited[j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	generatePrimes();

	for(cin >> t; t > 0; t--)
	{
		cin >> n;

		auto start = lower_bound(primes.begin(), primes.end(), n / 2);

		for(; start < primes.end(); start++)
		{
			int p = *start;
			auto it = lower_bound(primes.begin(), primes.end(), n - p);

			if(*it == n - p)
			{
				cout << *it << ' ' << p << '\n';
				break;
			}
		}
	}
}