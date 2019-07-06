#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, A, B, cache[30002];
bool isPrime[30002];

void generatePrime()
{
	for(int i = 2; i <= 30000; i++)
	{
		cache[i] = -1;
		isPrime[i] = true;
	}

	for(int i = 2; i <= 30000; i++)
	{
		if(!isPrime[i])
			cache[i] = 0;
		else
		{
			for(int j = 2 * i; j <= 30000; j += i)
				isPrime[j] = false;
		}
	}
}

int dp(int n)
{
	int& ret = cache[n];
	if(ret != -1)
		return ret;

	ret = max(ret, dp(n / 10));
	for(int i = 10; i <= 10000; i *= 10)
	{
		if(n < i)
			break;

		ret = max(ret, dp(n / (i * 10) * i + n % i));
	}

	return ret += 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	generatePrime();

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << "\n";
		cin >> A >> B;

		int score1 = dp(A), score2 = dp(B);

		if(score1 > score2)
			cout << 1 << '\n';
		else if(score1 < score2)
			cout << 2 << '\n';
		else
			cout << 3 << '\n';
	}
}