#include<iostream>

using namespace std;

long long n, k;
long long D[1002];

long long fac(long long num){
	if(num == 0)
		return 1;
	if(D[num])
		return D[num];
	else
		return D[num] = num * fac(num - 1);
}

int main(){
	cin >> n >> k;
	long long check;
	
	for(check = 0; fac(check) <= n + 1; check++){}
	
	if(check < k)
		printf("NO\n");
	else if((n + 1) % fac(k) == 0)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
