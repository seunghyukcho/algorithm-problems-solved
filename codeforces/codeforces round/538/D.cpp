#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[5002][5002][2];
int c[5002];
int dy(int l, int r, int dir)
{
	int& here = d[l][r][dir];
	if(here != -1) return here;
	if(l == r) return here = 0;

	if(dir == 0)
	{
		here = dy(l + 1, r, 0);
		here += (c[l] == c[l + 1]) ? 0 : 1;

		if(c[l] == c[r]) here = min(here, dy(l + 1, r, 1));
		else here = min(here, dy(l + 1, r, 1) + 1);
	}
	else
	{
		here = dy(l, r - 1, 1);
		here += (c[r] == c[r - 1]) ? 0 : 1;

		if(c[r] == c[l]) here = min(here, dy(l, r - 1, 0));
		else here = min(here, dy(l, r - 1, 0) + 1);
	}

	return here;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++) d[i][j][0] = d[i][j][1] = -1;
	}

	printf("%d\n", min(dy(1, n, 0), dy(1, n, 1)));

	return 0;
}