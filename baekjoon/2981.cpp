#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, num[102], gd;
vector<int> diff, ans;

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> num[i];
	
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			diff.push_back(abs(num[i] - num[j]));

	gd = diff[0];
	for(int i = 1; i < diff.size(); i++)
		gd = gcd(gd, diff[i]);

	for(int i = 1; i * i <= gd; i++)
		if(gd % i == 0)
		{
			if(i != 1 && i != gd / i)
				ans.push_back(i);
			ans.push_back(gd / i);
		}

	sort(ans.begin(), ans.end());

	for(int i : ans)
		cout << i << ' ';
	cout << '\n';
}