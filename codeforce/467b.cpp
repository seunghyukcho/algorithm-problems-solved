#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int p, y, ans = -1;

bool isprime(int num){
	for(int i = 2; i <= min(p, (int)sqrt(num)); i++)
		if(num % i == 0)
			return false;
	return true;
}

int main(){
	cin >> p >> y;
	
	for(int i = y; i > p; i--)
		if(isprime(i)){
			ans = i;
			break;
		}
	
	cout << ans << '\n';
	
	return 0;
}
