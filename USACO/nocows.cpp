/*
ID : choseun1
TASK : nocows
LANG : C++11
*/

#include<iostream>

using namespace std;

int D[203][102];
int N, K;

int dy(int n, int k){
	if(n <= 0 || k <= 0)
		return 0;
	if(n == 1)
		return 1;
	if(D[n][k] != -1)
		return D[n][k];
			
	int ret = 0;
	for(int i = 0; i < n; i++)
		ret = (ret + dy(n - 1 - i, k - 1) * dy(i, k - 1)) % 9901;
	
	
	return D[n][k] = ret;
}

int main(){
	freopen("nocows.in","r", stdin);
	freopen("nocows.out","w", stdout);
	
	cin >> N >> K;
	
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= K; j++)
			D[i][j] = -1;
			
	cout << (9901 + dy(N, K) - dy(N, K - 1)) % 9901 << '\n';
	
	return 0;
}
