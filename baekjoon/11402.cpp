#include<iostream>

using namespace std;

long long MOD;

long long pow(long long a, long long b) {
    if(b == 0) return 1;
    else {
        long long ret = pow(a, b / 2);
        if(b % 2) return (ret * ret % MOD) * (a % MOD) % MOD;
        else return ret * ret % MOD;
    }
}

long long factorial(long long num) {
    long long ret = 1;

    for(int i = 1; i <= num; i++) ret = ret * (i % MOD) % MOD;

    return ret;
}

int main(){
    int n, m;
    cin >> n >> m >> MOD;

    long long part1 = factorial(n);
    long long part2 = factorial(n - m) * factorial(m) % MOD;
    long long part3 = pow(part2, MOD - 2);

    cout << part1 * part3 % MOD << '\n';

    return 0;
}
