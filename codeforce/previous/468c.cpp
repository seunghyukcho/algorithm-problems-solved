#include<iostream>
#include<algorithm>

using namespace std;

int n, num[100002];
int check[3];

int main(){
	int mn = 1e7, mx = -1e7;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
		mn = min(mn, num[i]);
		mx = max(mx, num[i]);
	}
	
	if(mn == mx || mn + 1 == mx){
		cout << n << '\n';
		for(int i = 0; i < n; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else{
		for(int i = 0; i < n; i++)
			check[num[i] - mn]++;
		
		int n1 = min(check[2], check[0]) * 2;
		int n2 = check[1] - (check[1] % 2);
		int ans = 0;
		
		if(n1 >= n2){
			check[0] -= n1 / 2;
			check[2] -= n1 / 2;
			check[1] += n1;
			ans = n1;
		}
		else{
			check[1] -= n2;
			check[0] += n2 / 2;
			check[2] += n2 / 2;
			ans = n2;
		}
		
		cout << n - ans << '\n';
		for(int i = 0; i <= 2; i++)
			for(int j = 0; j < check[i]; j++)
				cout << mn + i << ' ';
		cout << '\n';
	}
	
	return 0;
}
