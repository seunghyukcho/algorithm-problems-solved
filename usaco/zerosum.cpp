/*
ID : choseun1
TASK : zerosum
LANG : C++11
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int n;
char sign[12];
vector<string> ans;

void check_sum(int sum, int dep, int p, int num){
	if(dep == 0){
		if(sum == 0){
			string s;
			for(int i = 1; i < n; i++){
				s.push_back(i + '0');
				s.push_back(sign[i + 1]);
			}
			s.push_back(n + '0');
			ans.push_back(s);
		}
	}
	else if(dep == 1){
		sum += num;
		check_sum(sum, 0, 0, 0);
	}
	else{
		if(sign[dep] == '+'){
			sum += num;
			num = dep - 1;
			p = 1;
		}
		else if(sign[dep] == '-'){
			sum -= num;
			num = dep - 1;
			p = 1;
		}
		else{
			num += pow(10, p) * (dep - 1);
			p++;
		}
		check_sum(sum, dep - 1, p, num);
	}
}

void make_seq(int dep){
	if(dep > n){
		check_sum(0, n, 1, n);
		return;
	}
	sign[dep] = '+';
	make_seq(dep + 1);
	sign[dep] = '-';
	make_seq(dep + 1);
	sign[dep] = ' ';
	make_seq(dep + 1);
}

int main(){
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	
	cin >> n;
	make_seq(2);
	
	sort(ans.begin(), ans.end());
	for(auto print : ans)
		cout << print << '\n';
	
	return 0;
}
