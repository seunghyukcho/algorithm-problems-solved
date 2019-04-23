#include <iostream>

using namespace std;

int n;
int area[500][500];

void draw(int x, int y, int h)
{
	if(h == 0)
		area[x][y] = 1;
	else
	{
		draw(x + 2, y + 2, h - 1);
		for(int i = 0; i < 4 * h + 1; i++)
		{
			area[x][y + i] = area[x + 4 * h][y + i] = 1;
			area[x + i][y] = area[x + i][y + 4 * h] = 1;
		}
	}
}

int main()
{
	cin >> n;

	draw(0, 0, n - 1);
	for(int i = 0; i < 4 * n - 3; i++)
	{
		for(int j = 0; j < 4 * n - 3; j++)
			cout << (area[i][j] == 1 ? '*' : ' ');
		cout << '\n';
	}

}