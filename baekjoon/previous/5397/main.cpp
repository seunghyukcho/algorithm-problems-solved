#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

char s[1000002];

int main(){
	int t;
	cin >> t;
	getchar();
	while(t){
		gets(s);
		
		list<char> password;
		auto it = password.begin();
		
		for(int i = 0; i < strlen(s); i++){
			char ch = s[i];
			if(ch == '>'){
				if(it != password.begin())
					it--;
			}
			else if(ch == '<'){
				if(it != password.end())
					it++;
			}
			else if(ch == '-'){
				if(!password.empty())
					it = password.erase(it);
			}
			else{
				it = password.insert(it, ch);
			}
		}
		
		reverse(password.begin(), password.end());
		for(auto ch : password)
			cout << ch;
		
		cout << '\n';
		t--;
	}
	
	return 0;
}
				
