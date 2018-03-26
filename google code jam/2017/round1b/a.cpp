#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, d, n;

int main(){
  cin >> t;
  for(int cs = 1; cs <= t; cs++){
    double min_time = 0;

    cin >> d >> n;
    for(int i = 0; i < n; i++){
      int k, s;
      cin >> k >> s;
      min_time = max(min_time, (double)(d - k) / s);
    }

    printf("Case #%d: %.6f\n", cs, d / min_time);
  }

  return 0;
}
