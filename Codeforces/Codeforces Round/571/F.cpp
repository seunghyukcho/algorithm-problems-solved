#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Edge
{
	int start, end;
} E[1000002];

int n, m, d[1000002], f[1000002];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> E[i].start >> E[i].end;
		d[E[i].start]++;
		d[E[i].end]++;

		f[E[i].start]++;
		f[E[i].end]++;
	}

	int remain = m;
	for(int i = 0; i < m; i++)
	{
		int s = E[i].start, e = E[i].end;
		if(remain <= (n + m + 1) / 2)
			ans.push_back(i);
		else if(f[s] - 1 < (d[s] + 1) / 2 || f[e] - 1 < (d[e] + 1) / 2)
			ans.push_back(i);
		else if(remain > (n + m + 1) / 2 && (f[s] - 1 >= (d[s] + 1) / 2 && f[e] - 1 >= (d[e] + 1) / 2))
		{
			remain--;
			f[s]--;
			f[e]--;
		}
	}

	cout << remain << '\n';
	for(int idx : ans)
	{
		cout << E[idx].start << ' ' << E[idx].end << '\n';
	}
}