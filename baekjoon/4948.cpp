#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> primes;

void generatePrimes()
{
	vector<bool> visited(300002, false);

	for(int i = 2; i <= 300000; i++)
	{
		if(!visited[i])
		{
			primes.push_back(i);

			for(long long j = (long long)i * i; j <= 300000; j += i)
				visited[j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	generatePrimes();

	while(1)
	{
		cin >> n;
		if(n == 0)
			break;

		auto it1 = upper_bound(primes.begin(), primes.end(), n);
		auto it2 = upper_bound(primes.begin(), primes.end(), 2 * n);

		cout << it2 - it1 << '\n';

	}
}