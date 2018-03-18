/*
ID : choseun1
TASK : lamps
LANG : C++11
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int n, c;
vector<string> ans;
vector<int> turn_on;
vector<int> turn_off;
map<pair<string, int>, bool> D;

void dy(string s, int dep){
	pair<string, int> here = make_pair(s, dep);
	D[here] = true;
	
	if(dep == c){
		for(int i = 0; i < turn_on.size(); i++)
			if(s[turn_on[i] - 1] != '1')
				return;
		for(int i = 0; i < turn_off.size(); i++)
			if(s[turn_off[i] - 1] != '0')
				return;
		ans.push_back(s);
		return;
	}
	
	string new_s = s;
	for(int i = 0; i < s.size(); i++)
		new_s[i] = (s[i] == '1' ? '0' : '1');
		
	here = make_pair(new_s, dep + 1);
	if(D.find(here) == D.end())
		dy(new_s, dep + 1);
	
	new_s = s;
	for(int i = 0; i < s.size(); i++)
		if(i % 2)
			new_s[i] = (s[i] == '1' ? '0' : '1');
	here = make_pair(new_s, dep + 1);
	if(D.find(here) == D.end())
		dy(new_s, dep + 1);
	
	new_s = s;
	for(int i = 0; i < s.size(); i++)
		if(i % 2 == 0)
			new_s[i] = (s[i] == '1' ? '0' : '1');
	here = make_pair(new_s, dep + 1);
	if(D.find(here) == D.end())
		dy(new_s, dep + 1);
	
	new_s = s;
	for(int i = 0; i < s.size(); i++)
		if((i + 1) % 3 == 1)
			new_s[i] = (s[i] == '1' ? '0' : '1');
	here = make_pair(new_s, dep + 1);
	if(D.find(here) == D.end())
		dy(new_s, dep + 1);
}

int main(){
	//freopen("lamps.in", "r", stdin);
	//freopen("lamps.out", "w", stdout);
	cin >> n >> c;
	int input;
	while(1){
		cin >> input;
		if(input == -1)
			break;
		turn_on.push_back(input);
	}
	while(1){
		cin >> input;
		if(input == -1)
			break;
		turn_off.push_back(input);
	}
	string start;
	for(int i = 0; i < n; i++)
		start.push_back('1');
	dy(start, 0);
	sort(ans.begin(), ans.end());
	
	if(ans.size() == 0)
		cout << "IMPOSSIBLE\n";
	else
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	
	return 0;
}


