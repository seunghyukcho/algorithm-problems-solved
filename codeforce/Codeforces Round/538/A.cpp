#include <iostream>

using namespace std;

int x, y, z;
int a, b, c;

int main()
{
	int sum = 0;
	cin >> x >> y >> z;
	cin >> a >> b >> c;

	a -= x;
	if(a < 0) 
		printf("NO\n");

	else if(a + b < y)
		printf("NO\n");

	else if(a + b + c - y < z)
		printf("NO\n");

	else
		printf("YES\n");

	return 0;
}