#include <iostream>

using namespace std;

int n;
char area[3000][3000];

void draw(int x, int y, int h, int dir)
{
	if(h == 1)
		area[x][y] = '*';
	else if(h == 3)
	{
		if(dir == 1)
		{
			for(int i = 0; i < h; i++)
			{
				for(int j = 0; j < h - i - 1; j++)
					area[x + i][y + j] = ' ';
				for(int j = 0; j < 2 * i + 1; j++)
					area[x + i][y + h - 1 - i + j] = '*';
			}
		}
		else
		{
			for(int i = h - 1; i >= 0; i--)
			{
				for(int j = 0; j < h - i - 1; j++)
					area[x + h - 1 - i][y + j] = ' ';
				for(int j = 0; j < 2 * i + 1; j++)
					area[x + h - 1 - i][y + h - 1 - i + j] = '*';
			}
		}
	}
	else
	{
		if(dir == 1)
		{
			for(int i = 1; i < h; i++)
			{
				for(int j = 0; j < h - i; j++)
					area[x + i - 1][y + j] = ' ';
				area[x + i - 1][y + h - i] = '*';

				if(i != 1) 
				{
					for(int j = 0; j < 2 * i - 3; j++)
						area[x + i - 1][y + h - i + j + 1] = ' ';
					area[x + i - 1][y + h - i + 2 * i - 2] = '*';
				}
			}

			for(int i = 0; i < 2 * h - 1; i++)
				area[x + h - 1][y + i] = '*';
			draw(x + h / 2, y + h / 2 + 1, h / 2, 0);
		}
		else
		{
			for(int i = 0; i < 2 * h - 1; i++)
				area[x][y + i] = '*';

			for(int i = h - 1; i >= 1; i--)
			{
				for(int j = 0; j < h - i; j++)
					area[x + h - i][y + j] = ' ';

				area[x + h - i][y + h - i] = '*';
				if(i != 1) 
				{
					for(int j = 0; j < 2 * i - 3; j++)
						area[x + h - i][y + h - i + j + 1] = ' ';
					area[x + h - i][y + h - i + 2 * i - 2] = '*';
				}
			}
			draw(x + 1, y + h / 2 + 1, h / 2, 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < 3000; i++)
		for(int j = 0; j < 3000; j++)
			area[i][j] = '-';

	cin >> n;
	int h = (1 << n) - 1;
	draw(0, 0, h, n % 2);

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < 2 * h - 1; j++)
			if(area[i][j] != '-')
				cout << area[i][j];
		cout << '\n';
	}
}