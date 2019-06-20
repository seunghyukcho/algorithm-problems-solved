#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int m, k, play[30];
int cache[3000];
ll ans;

int func(int n)
{
	if(n < play[0])
		return 0;
	int& ret = cache[n];
	if(ret != -1)
		return ret;

	for(int i = 0; i < k; i++)
	{
		if(n < play[i])
			continue;

		if(!func(n - play[i]))
			return ret = 1;
	}
	
	return ret = 0;
}

int main()
{
	cin >> m >> k;
	for(int i = 0; i < k; i++)
		cin >> play[i];
	for(int i = 0; i < 3000; i++)
		cache[i] = -1;

	int l = 100;
	while(1)
	{
		bool flag = true;
		for(int i = 1; true && i <= l; i++)
			if(func(i + 500) != func(i + l + 500))
				flag = false;

		if(flag)
			break;
		l++;
	}

	for(int i = 1; i <= min(m, 500); i++)
		if(func(i))
			ans++;

	ll ans2 = 0;
	for(int i = 1; i <= l; i++)
		if(func(i + 500))
			ans2++;

	if(m > 500)
	{
		ans = ans + (ans2 * ((m - 500) / l));

		for(int j = 1; j <= (m - 500) % l; j++)
			if(func(500 + j))
				ans++;
	}

	cout << m - ans << '\n';
}