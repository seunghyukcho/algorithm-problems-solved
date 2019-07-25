#include<iostream>
#include<algorithm>

using namespace std;

int n, m[100002];
int ans[100002][2];

int main(){
  long long ans2 = 0;

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> m[i];

  for(int i = 1; i <= n; i++){
    if(i == 1)
      ans[i][0] = ans[i][1] = 1;
    else{
      ans[i][1] = i;
      ans[i][0] = max(m[i] + 1, ans[i - 1][0]);
      ans[i - 1][0] = max(ans[i - 1][0], ans[i][0] - 1);
    }
  }

  for(int i = n; i > 1; i--){
    ans2 += ans[i][0] - 1 - m[i];
    ans[i - 1][0] = max(ans[i - 1][0], ans[i][0] - 1);
  }

  printf("%lld\n", ans2);

  return 0;
}
