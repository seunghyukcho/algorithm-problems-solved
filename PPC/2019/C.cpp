#include <iostream>
#include <cmath>

using namespace std;

double ha, hb, hc;

int main()
{
	scanf("%lf %lf %lf", &ha, &hb, &hc);

	double up = pow(ha * hb * hc, 2);
	double s1 = ha * hb;
	double s2 = ha * hc;
	double s3 = hb * hc;

	double down = (s1 + s2 + s3) * (-s1 + s2 + s3) * (s1 - s2 + s3) * (s1 + s2 - s3);
	
	printf("%.10lf", up / sqrt(down));
}