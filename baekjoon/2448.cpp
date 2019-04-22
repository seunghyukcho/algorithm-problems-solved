#include <iostream>

using namespace std;

int n;
int area[3100][6202];

void draw(int x, int y, int h)
{
	if(h == 3)
	{
		area[x][y + 2] = 1;
		area[x + 1][y + 1] = area[x + 1][y + 3] = 1;
		for(int i = 0; i < 5; i++)
			area[x + 2][y + i] = 1;
	}
	else
	{
		draw(x, y + h / 2, h / 2);
		draw(x + h / 2, y, h / 2);
		draw(x + h / 2, y + h, h / 2);
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
		for(int j = 0; j < 2 * n; j++)
			cout << (area[i][j] == 0 ? ' ' : '*');
		cout << '\n';
	}
}