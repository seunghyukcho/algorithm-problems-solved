#include<iostream>

using namespace std;

int n, a, b;

int main(){
	int round = 1;
	
	cin >> n >> a >> b;
	
	while((a - 1) / (1 << round) != (b - 1) / (1 << round))
		round++;
	
	if((1 << round) == n)
		cout << "Final!" << '\n';
	else
		cout << round << '\n';
		
	return 0;
}
