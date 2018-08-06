#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long MOD = 1000000007;
long long pow(int num) {
    if(num == 0) return 1;
    long long ret = pow(num / 2);
    if(num % 2) return (((ret * ret) % MOD) * 2) % MOD;
    else return ret * ret % MOD;
}

int main(){
    long long n, c, k;
    ios::sync_with_stdio(false);

    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> c >> k;
        if(k == 0) continue;

        c *= k;
        k--;

        ans = (ans + c * pow(k) % MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
