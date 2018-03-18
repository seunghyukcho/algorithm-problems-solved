/*
ID : choseun1
TASK : sort3
LANG : C++11
*/

#include<iostream>

using namespace std;

int cnt[4];
int seg[4][4];
int n;
int num[1002];

int main(){
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
		cnt[num[i] - 1]++;
	}
	
	for(int i = 0; i < n; i++){
		if(i < cnt[0])
			seg[1][num[i]]++;
		else if(i >= cnt[0] && i < cnt[0] + cnt[1])
			seg[2][num[i]]++;
		else
			seg[3][num[i]]++;
	}
	
	int ans = 0;
	
	if(seg[1][2] < seg[2][1]){
		ans += seg[2][1];
		
		seg[2][3] += seg[2][1] - seg[1][2];
		seg[1][3] -= seg[2][1] - seg[1][2];
		
		seg[2][2] += seg[1][2];
		seg[1][2] = seg[2][1] = 0;
	}
	else{
		ans += seg[1][2];
		
		seg[1][3] += seg[1][2] - seg[2][1];
		seg[2][3] -= seg[1][2] - seg[2][1];
		
		seg[1][2] += seg[2][1];
		seg[2][2] = seg[1][2] = 0;
	}
	
	ans += seg[3][1] + seg[3][2];
	
	cout << ans << '\n';
	
	return 0;
}
		
		
