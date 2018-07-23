#include<iostream>

using namespace std;

long long D[1000002], MOD = 1000000009;
int n, k;

int main(){
    cin >> n >> k;
    D[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i < 5) D[i] = D[i - 1] * k % MOD;
        else {
            D[i] = (D[i - 1] * k % MOD - 2 * D[i - 5]);
            while(D[i] < 0) D[i] += MOD;
            D[i] %= MOD;
        }
    }

    cout << D[n] << '\n';

    return 0;
}
