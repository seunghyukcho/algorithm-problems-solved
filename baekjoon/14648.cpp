#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int n, q;
long long A[1001];

struct Segment{
  long long sum[400000];

  Segment(){
    for(int i = 0; i < 400000; i++)
      sum[i] = 0;
  }

  long long get(int l, int r, int left = 0, int right = n - 1, int v = 1){
    if(left > r || right < l)
      return 0;
    if(left >= l && r >= right)
      return sum[v];
    else{
      int mid = (left + right) / 2;
      return get(l, r, left, mid, v * 2) + get(l, r, mid + 1, right, v * 2 + 1);
    }
  }

  void change(int idx, int modify, int left = 0, int right = n - 1, int v = 1){
    if(left > idx || right < idx)
      return;
    sum[v] += modify;
    if(left == right)
      return;
    int mid = (left + right) / 2;
    change(idx, modify, left, mid, v * 2);
    change(idx, modify, mid + 1, right, v * 2 + 1);
  }
};

int main(){
  Segment tree;

  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> A[i];

    tree.change(i, A[i], 0, n - 1, 1);
  }

  for(int i = 0; i < q; i++){
    int num;
    cin >> num;
    if(num == 1){
      int a, b;
      cin >> a >> b;

      int modify = A[b - 1] - A[a - 1];
      swap(A[a - 1], A[b - 1]);
      cout << tree.get(a - 1, b - 1) << '\n';
      tree.change(a - 1, modify);
      tree.change(b - 1, -modify);
    }
    else{
      int a, b, c, d;
      cin >> a >> b >> c >> d;

      cout << tree.get(a - 1, b - 1) - tree.get(c - 1, d - 1) << '\n';
    }
  }

  return 0;
}
