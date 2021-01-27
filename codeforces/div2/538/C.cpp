#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n, b;
vector<long long> prime;
vector<pair<long long, int> > d;

void prime_generate()
{
	vector<bool> v = vector<bool>(1000000, false);

	for(int i = 2; i <= 1000000; i++)
	{
		if(!v[i])
		{
			v[i] = true;
			prime.push_back(i);

			for(int j = i; j <= 1000000; j += i)
				v[j] = true;
		}
	}
}

int main()
{
	cin >> n >> b;

	prime_generate();
	for(long long p : prime)
	{
		int cnt = 0;
		while(b % p == 0)
		{
			cnt++;
			b /= p;
		}

		if(cnt > 0)
			d.push_back({ p, cnt });
	}

	if(b > 1) d.push_back({ b, 1 });

	long long mn = 1e18;
	for(pair<long long, int> p : d)
	{
		long long cnt = 0;
		long long start = p.first;
		long long newn = n;
		
		while(newn)
		{
			newn /= start;
			cnt += newn;
		}

		mn = mn > cnt / p.second ? cnt / p.second : mn;
	}

	printf("%lld\n", mn);

	return 0;

}