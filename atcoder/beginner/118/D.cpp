#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, a[10], cnt[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int d[10002];
string ans[10002];

string dy(int n)
{
	int& ret = d[n];
	int here = 0;
	if(ret != -1) return ret;

	for(int i = 1; i <= m; i++)
	{
		if(ret < dy(n - cnt[a[i]]))
		{
			here = i;
			ret = dy(n - cnt[a[i]]);
		}
		else if(ret == dy(n - cnt[a[i]]) && a[i] > a[here])
		{
			here = i;
		}
	}

	ret = (ret == -1 ? -2 : ret + 1);
	ans[n] = (ret == -2 ? "" : ans[n - cnt[a[here]]] + )
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 0; i <= n; i++) d[i] = -1;
	

}