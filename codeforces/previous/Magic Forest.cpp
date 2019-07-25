#include<iostream>

using namespace std;

int n, ans;
int check[2501][2501][2501];

void dfs(int lim, int a, int b, int c){
	if(lim == 0){
		if(a <= n && b <= n && c <= n && a + b > c && b + c > a && c + a > b && !check[a][b][c]){
			ans++;
			check[a][b][c] = true;
		}
		
		return;
	}
	
	dfs(lim - 1, (a << 1) + 1, (b << 1) + 1, (c << 1));
	dfs(lim - 1, (a << 1) + 1, (b << 1), (c << 1) + 1);
	dfs(lim - 1, (a << 1), (b << 1) + 1, (c << 1) + 1);
	dfs(lim - 1, (a << 1), (b << 1), (c << 1));
}

int main(){
	cin >> n;
	int limit = 0;
	
	for(int i = 1; i <= n; i *= 2)
		limit++;
	
	for(int i = 0; i <= limit; i++)
		dfs(i + 1, 0, 0, 0);
	
	printf("%d\n", ans / 6);
	
	return 0;
}
