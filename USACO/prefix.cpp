/*
ID : choseun1
TASK : prefix
LANG : C++11
*/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

vector<string> prim;
string s;
int D[200003];

int dy(int n){
	if(n < 0)
		return 1;
	if(D[n] != 0)
		return D[n];
	int ret = -1;
	
	for(int i = 0; i < prim.size(); i++){
		string next = prim[i];
		bool check = true;
		for(int j = 0; j < next.size(); j++){
			if(next.size() > n + 1 || next[j] != s[n - next.size() + j + 1]){
				check = false;
				break;
			}
		}
		if(check){
			if(dy(n - next.size()) == 1){
				ret = 1;
				break;
			}
		}
	}
	
	return D[n] = ret;
}

int main(){
	ifstream inf("prefix.in");
	freopen("prefix.out", "w", stdout);
	
	string input;
	int sz = 0;
	while(1){
		inf >> input;
		if(input == ".")
			break;
		prim.push_back(input);
	}
	while(!inf.eof()){
		inf >> input;
		s += input;
		sz = input.size();
	}
	
	for(int i = 0; i < sz; i++)
		s.pop_back();
	int ans = 0;
	
	for(int i = 0; i < s.size(); i++)
		if(dy(i) == 1)
			ans = ans < i + 1 ? i + 1 : ans;
	
	cout << ans << '\n';
	
	return 0;
}
