#include<iostream>
#include<string>

using namespace std;

string s;
int cnt[50], ans[2];

int main(){
  cin >> s;

  for(auto ch : s){
    cnt[ch - 'a']++;
    if(cnt[ch - 'a'] == 1)
      ans[0]++;
    if(cnt[ch - 'a'] == 2){
      ans[1]++;
      ans[0]--;
    }
  }

  if(ans[0] + ans[1] == 2 && !ans[0])
    printf("Yes\n");
  else if(ans[0] + ans[1] == 3 && ans[1])
    printf("Yes\n");
  else if(ans[0] + ans[1] == 4)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
