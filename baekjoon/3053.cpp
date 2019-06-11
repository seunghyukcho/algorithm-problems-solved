#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int r;
	scanf("%d", &r);

	printf("%.5f %.5f\n", M_PI * pow(r, 2), pow(r, 2) * 2);
}