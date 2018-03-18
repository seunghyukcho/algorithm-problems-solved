/*
ID : choseun1
TASK : money
LANG : C++11
*/
#include<iostream>
#include<vector>

using namespace std;

long long D[10002];
vector<int> coin;
int v, n;

int main(){
	freopen("money.in","r", stdin);
	freopen("money.out","w", stdout);
	
	cin >> v >> n;
	for(int i = 0; i < v; i++){
		int num;
		cin >> num;
		coin.push_back(num);
	}
	
	D[0] = 1;
	for(int here : coin){
		for(int i = 0; i < n; i++){
			if(D[i]){
				int next = here + i;
				if(next <= n)
					D[next] += D[i];
			}
		}
	}
	
	cout << D[n] << '\n';
	
	return 0;
}
