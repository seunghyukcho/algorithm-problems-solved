#include<iostream>

using namespace std;

long long k, d, t;
double ans;

int main(){
	long long input_d;
	cin >> k >> input_d >> t;
	
	if(k % input_d == 0)
		d = k;
	else
		d = input_d * (long long)(k / input_d + 1);
	
	double cycle = (k + d) / 2.0;
	ans += (double)((long long)(t / cycle) * d);
	
	double rest = t - ans / d * cycle;
	
	if(rest <= k)
		ans += rest;
	else
		ans += 2 * rest - k;
		
	printf("%.10lf\n", ans);
	
	return 0;
}

