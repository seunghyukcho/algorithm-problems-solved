#include<iostream>
#include<algorithm>
#include<vector>
#define SIZE 500

using namespace std;

struct Query {
    int left;
    int right;
    int index;
    long long ans;
} Q[100002];

int n, t, a[100002];
long long check[1000002];

bool cmp1(Query A, Query B){
    if(A.left / 500 == B.left / 500) return A.right / 500 < B.right / 500;
    return A.left / 500 < B.left / 500;
}

bool cmp2(Query A, Query B){
    return A.index < B.index;
}

int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < t; i++){
        cin >> Q[i].left >> Q[i].right;
        Q[i].index = i;
        Q[i].ans = 0;

        Q[i].left -= 1;
        Q[i].right -= 1;
    }

    sort(Q, Q + t, cmp1);
    long long sum = 0;

    for(int i = Q[0].left; i <= Q[0].right; i++){
        int s = a[i];
        sum -= check[s] * check[s] * s;
        check[s]++;
        sum += check[s] * check[s] * s;
    }
    Q[0].ans = sum;

    int L = Q[0].left, R = Q[0].right;

    for(int i = 1; i < t; i++){
        if(Q[i].left < L){
            for(int j = Q[i].left; j < L; j++){
                int s = a[j];
                sum -= check[s] * check[s] * s;
                check[s]++;
                sum += check[s] * check[s] * s;
            }
        }
        else {
            for(int j = L; j < Q[i].left; j++){
                int s = a[j];
                sum -= check[s] * check[s] * s;
                check[s]--;
                sum += check[s] * check[s] * s;
            }
        }
        L = Q[i].left;

        if(Q[i].right > R){
            for(int j = R + 1; j <= Q[i].right; j++){
                int s = a[j];
                sum -= check[s] * check[s] * s;
                check[s]++;
                sum += check[s] * check[s] * s;
            }
        }
        else {
            for(int j = Q[i].right + 1; j <= R; j++){
                int s = a[j];
                sum -= check[s] * check[s] * s;
                check[s]--;
                sum += check[s] * check[s] * s;
            }
        }
        R = Q[i].right;

        Q[i].ans = sum;
    }

    sort(Q, Q + t, cmp2);
    for(int i = 0; i < t; i++) cout << Q[i].ans << '\n';

    return 0;
}
