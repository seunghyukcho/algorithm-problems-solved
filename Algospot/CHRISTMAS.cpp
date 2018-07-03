#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 20091101

using namespace std;

int t, n, k;
int psum[100010];
long long check[100010];

int prob1(){
    int ret = 0;

    for(int i = 0; i < k; i++){
        if(check[i] >= 2) ret = (ret + (check[i] * (check[i] - 1)) / 2) % MOD;
    }

    return ret;
}

int prob2(){
    int ret = 0;
    vector<int> D(n + 1, 0);
    vector<int> prev(k + 1, -1);

    prev[0] = 0;
    for(int i = 1; i <= n; i++){
        D[i] = D[i - 1];
        if(prev[psum[i]] != -1) D[i] = max(D[i], D[prev[psum[i]]] + 1);
        prev[psum[i]] = i;
    }

    return D[n];
}

int main(){
    for(cin >> t; t > 0; t--){
        cin >> n >> k;

        for(int i = 0; i < k; i++) check[i] = 0;
        psum[0] = 0;
        check[0] = 1;

        for(int i = 1; i <= n; i++){
            int num;
            cin >> num;

            psum[i] = (psum[i - 1] + num) % k;
            check[psum[i]]++;
        }

        cout << prob1() << ' ' << prob2() << '\n';
    }
    return 0;
}
