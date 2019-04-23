#include <iostream>

using namespace std;

int n;
char area[500][500];

void draw(int x, int y, int h, int flag)
{
	if(h == 0)
	{
		area[x][y] = '*';
		area[x + 1][y] = '*';
		area[x + 2][y] = '*';
	}
	else
	{
		draw(x + 2, y + 2, h - 1, 0);

		for(int i = 0; i < 4 * h + 1; i++)
		{
			area[x][y + i] = area[x + 4 * h + 2][y + i] = '*';
			area[x + i + 1][y] = '*';
			area[x + i + 1][y + 1] = ' ';
			if(i != 0)
			{
				area[x + i + 1][y + 4 * h] = '*';
				if(flag == 0)
					area[x + 1][y + i] = ' ';
			}
			if(i > 1)
			{
				area[x + 4 * h + 1][y + i - 1] = ' ';
				area[x + 1 + i][y + 4 * h - 1] = ' ';
			}
		}
		area[x + 2][y + 4 * h - 1] = '*';


	}
}

int main()
{
	cin >> n;

	if(n == 1)
		cout << "*\n";
	else
	{
		for(int i = 0; i < 500; i++)
			for(int j = 0; j < 500; j++)
				area[i][j] = '-';
		draw(0, 0, n - 1, 1);

		for(int i = 0; i < 4 * n - 1; i++)
		{
			for(int j = 0; j < 4 * n - 3; j++)
				if(area[i][j] != '-')
					cout << area[i][j];
			cout << '\n';
		}
	}

}