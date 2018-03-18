#include<iostream>

using namespace std;

int a, b;

int main(){
	cin >> a >> b;
	
	int dif = b - a;
	dif = dif > 0 ? dif : -dif;
	
	int n1 = dif / 2;
	int n2 = dif - n1;
	
	cout << n1 * (n1 + 1) / 2 + n2 * (n2 + 1) / 2 << '\n';
	
	return 0;
}
