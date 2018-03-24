#include<iostream>
#include<algorithm>

using namespace std;

int n, m, A[100002];

struct Segment{
  int min_val[400000];
  Segment(){
    for(int i = 0; i < 400000; i++)
      min_val[i] = 1e9;
  }

  int get(int l, int r, int left = 0, int right = n - 1, int v = 1){
    if(right < l || left > r)
      return 1e9;
    if(left >= l && right <= r)
      return min_val[v];
    else{
      int mid = (left + right) / 2;
      return min(get(l, r, left, mid, v * 2), get(l, r, mid + 1, right, v * 2 + 1));
    }
  }

  int update(int idx, int num, int left = 0, int right = n - 1, int v = 1){
    if(right < idx || left > idx)
      return min_val[v];
    if(left == right){
      A[idx] = num;
      min_val[v] = num;
      return num;
    }
    else{
      int mid = (left + right) / 2;
      return min_val[v] = min(update(idx, num, left, mid, v * 2), update(idx, num, mid + 1, right, v * 2 + 1));
    }
  }
};

int main(){
  Segment tree;

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
    tree.update(i, A[i]);
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    int num;
    scanf("%d", &num);

    if(num == 1){
      int a, b;
      scanf("%d%d", &a, &b);

      tree.update(a - 1, b);
    }
    else{
      int a, b;
      scanf("%d%d", &a, &b);

      printf("%d\n", tree.get(a - 1, b - 1));
    }
  }

  return 0;
}
