#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, slots[1000002];
int k, p;

void FailureFunction(vector<int> &v)
{
	v = vector<int>(n + 1, 0);

	int j = 0;
	for(int i = 1; i < n; i++)
	{
		while(j > 0 && slots[i] != slots[j]) j = v[j - 1];

		if(slots[i] == slots[j])
			v[i] = ++j;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> pi;

	cin >> n;
	for(int i = n - 1; i >= 0; i--)
		cin >> slots[i];

	FailureFunction(pi);

	k = n - 1, p = 1;
	for(int i = 1; i < n; i++)
	{
		int hereK = n - i - 1;
		int hereP = i - pi[i] + 1;

		if(hereK + hereP < k + p || (hereK + hereP == k + p && hereP < p))
		{
			k = hereK;
			p = hereP;
		}
	}

	cout << k << ' ' << p << '\n';
}

