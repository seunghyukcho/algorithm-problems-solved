#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int n, r;
char map[1002][1002];
char ans[1002][1002];
char shape[4] = {'<', 'v', '>', '^'};

int main()
{
	string rotate;
	cin >> n >> rotate;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			ans[i][j] = '.';
		}

	for(char ch : rotate)
		r += (ch == 'L' ? -1 : 1);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(map[i][j] != '.')
			{
				int herex = (i < n / 2 ? i - n / 2 : i - (n - 1) / 2);
				int herey = (j < n / 2 ? j - n / 2 : j - (n - 1) / 2);

				for(int k = 0; k < abs(r) % 4; k++)
				{
					swap(herex, herey);
					if(r < 0)
						herex *= -1;
					else
						herey *= -1;
				}

				int s = 0;
				for(s = 0; s < 4; s++)
					if(map[i][j] == shape[s])
						break;

				for(int k = 0; k < abs(r) % 4; k++)
				{
					if(r < 0)
						s = (s + 1) % 4;
					else
						s = (s - 1 + 4) % 4;
				}

				int nextx = (herex < 0 ? herex + n / 2 : herex + (n - 1) / 2);
				int nexty = (herey < 0 ? herey + n / 2 : herey + (n - 1) / 2);
				ans[nextx][nexty] = shape[s];
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << ans[i][j];
		cout << '\n';
	}

}