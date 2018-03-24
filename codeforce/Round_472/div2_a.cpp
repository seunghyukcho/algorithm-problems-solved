#include<iostream>
#include<string>

using namespace std;

int n;
string s;

int main(){
  bool ans = false;

  cin >> n >> s;

  if(s[0] == '?' || s[s.size() - 1] == '?')
    ans = true;
  for(int i = 1; i < s.size() - 1; i++){
    if((s[i] == s[i - 1] || s[i] == s[i + 1]) && s[i] != '?'){
      ans = false;
      break;
    }
    if(s[i] == '?'){
      if((i != 0 && s[i - 1] == '?') || s[i + 1] == '?')
        ans = true;
      else if(s[i - 1] == s[i + 1])
        ans = true;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
