#include <iostream>

using namespace std;

int cache[1002][1002];
int map[1002][1002];
int n, m;

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			cache[i][j] = -1;
		}

	
}