#include<iostream>
#include<vector>

using namespace std;

vector<long long> D(101, -1);

long long Dy(int n){
	if(n < 3)return 1;
	if(D[n] != -1)return D[n];
	return D[n] = Dy(n-1) + Dy(n-2);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%lld\n",Dy(n));
	
	return 0;
}
