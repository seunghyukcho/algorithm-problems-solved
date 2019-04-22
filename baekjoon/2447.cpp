#include <iostream>

using namespace std;

int n;
int area[6600][6600];
void draw(int x, int y, int h)
{
	if(h == 1)
	{
		area[x][y] = 1;
	}
	else
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(i == 1 && j == 1)
					continue;
				draw(x + h * i / 3, y + h * j / 3, h / 3);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	draw(0, 0, n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << (area[i][j] == 0 ? ' ' : '*');
		cout << '\n';
	}
}