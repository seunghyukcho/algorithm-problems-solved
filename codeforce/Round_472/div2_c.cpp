#include<iostream>
#include<algorithm>

using namespace std;

int n, u;
int state[100002];

int main(){
  float ans = -1;

  cin >> n >> u;
  for(int i = 0; i < n; i++)
    cin >> state[i];
  for(int i = 0; i < n - 2; i++){
    int ei = state[i];
    int ej = state[i + 1];
    int ek = -1;

    int start = i + 2;
    int end = n - 1;

    while(start + 1 < end){
      int mid = (start + end) / 2;
      if(state[mid] > u + ei)
        end = mid - 1;
      else if(state[mid] < u + ei)
        start = mid;
      else{
        start = mid;
        break;
      }
    }

    if(state[start] > u + ei)
      continue;
    else if(start + 1 < end || start == end)
      ek = start;
    else if(start + 1 == end){
      if(state[end] <= u + ei)
        ek = end;
      else
        ek = start;
    }

    ans = max(ans, (float)(state[ek] - ej) / (state[ek] - ei));
  }
  
  if(ans == -1)
    printf("-1\n");
  else
    printf("%.9f\n", ans);

  return 0;
}
