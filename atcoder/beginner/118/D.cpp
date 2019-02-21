#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, a[10], cnt[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int d[10002];
string ans[10002];

int dy(int n)
{
	if(n < 0) return -2;
	
	int& ret = d[n];
	string& s = ans[n];

	int here = 0;
	if(ret != -1) return ret;

	for(int i = 1; i <= m; i++)
	{
		int next = dy(n - cnt[a[i]]);

		if(next == -2) continue;
		if(ret < next)
		{
			here = i;
			ret = next;
		}
		else if(ret == next && a[i] > a[here])
		{
			here = i;
		}
	}

	ret = (ret == -1 ? -2 : ret + 1);
	if(ret != -2)
	{
		char ch = a[here] + '0';
		s = ans[n - cnt[a[here]]];
		s.push_back(ch);
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 0; i <= n; i++) 
	{
		d[i] = -1;
		ans[i] = "";
	}

	d[0] = 0;
	
	dy(n);
	reverse(ans[n].begin(), ans[n].end());
	cout << ans[n] << '\n';
}