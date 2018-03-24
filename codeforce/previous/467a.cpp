#include<iostream>
#include<algorithm>

using namespace std;

int ans, n, people[102];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> people[i];
	
	sort(people, people + n);
	
	for(int i = 0; i < n; i++){
		int num = people[i];
		while(i < n && num == people[i])
			i++;
		if(num != 0)
			ans++;
		i--;
	}
	
	cout << ans << '\n';
	
	return 0;
}
