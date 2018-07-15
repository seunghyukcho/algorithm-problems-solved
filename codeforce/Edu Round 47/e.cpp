#include<iostream>

using namespace std;

long long MOD = 998244353;

long long p[1000002];
long long D[1000002];

long long pow(int n) {
    if(n == 0) return 1;
    if(p[n]) return p[n];

    long long ret = pow(n / 2);
    if(n % 2) ret = ((ret * ret) % MOD) * 2 % MOD;
    else ret = ret * ret % MOD;

    return p[n] = ret;
}

int n, a[1000002];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    D[1] = a[1];

    for(int i = 2; i <= n; i++) {
        D[i] = (2 * D[i - 1] % MOD + pow(i - 2) * a[1] % MOD + a[i]) % MOD;
        if(i != 2) D[i] = (D[i] + a[i - 1]) % MOD;
        cout << D[i] << '\n';
    }

    cout << D[n] << '\n';

    return 0;
}
