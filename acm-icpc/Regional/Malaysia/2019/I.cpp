#include <iostream>

using namespace std;

char map[4][11];
int x, y;

int main()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == '=')
			{
				x = i;
				y = j;
			}				
		}
	}

	for(int i = y + 1; i < 10; i++)
	{
		if(map[x][i] != '.')
		{
			cout << map[x][i] << '\n';
			return 0;
		}
	}

	cout << "You shall pass!!!" << '\n';
}