#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int seq[1000];
long long n, k;

int main(){
	int mid = 500;
	int ans = 0;
	int mx = -1;
	multiset<int> num;
	
	cin >> n >> k;
	
	for(int i = 0; n > 0; n /= 2, i++){
		if(n % 2 == 1){
			seq[mid + i] = 1;
			ans++;
			mx = max(i, mx);
		}
	}
	
	for(int i = mx; ans < k; i--){
		int here = i + mid;
		int add;
		
		if(ans + seq[here] > k){
			break;
		}
		else
			add = seq[here];
			
		ans += add;
		seq[here] -= add;
		seq[here - 1] += 2 * add;
	}
	
	for(int i = 999; i >= 0; i--)
		for(int j = 0; j < seq[i]; j++)
			num.insert(i - mid);
	
	while(ans < k){
		int next = *num.begin();
		num.erase(num.begin());
		ans++;
		num.insert(next - 1);
		num.insert(next - 1);
	}
	
	if(ans == k){
		printf("Yes\n");
		for(auto it = num.rbegin(); it != num.rend(); it++)
			printf("%d ", *it);
		printf("\n");
	}
	else
		printf("No\n");
	
	
	return 0;
}
	
