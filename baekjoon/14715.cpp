#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> prime;

void generatePrimes(int n)
{
	vector<bool> visited(n + 1, false);

	for(int i = 2; i <= n; i++)
	{
		if(!visited[i])
		{
			prime.push_back(i);

			for(int j = i; j <= n; j += i)
				visited[j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	generatePrimes(k);

	int here = 0, ans = 0;
	for(int p : prime)
	{
		while(k % p == 0)
		{
			k /= p;
			here++;
		}
	}

	while(here > 1)
	{
		here = (here / 2) + (here % 2);
		ans++;
	}

	cout << ans << '\n';
}