#include <iostream>
#include <string>

using namespace std;

double total;
string s;
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		double val;
		cin >> val >> s;
		if(s == "JPY") total += val;
		else total += val * 380000.0;
	}

	printf("%.6f\n", total);
}