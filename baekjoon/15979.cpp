#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a, int b) {
    return b % a ? gcd(b % a, a) : a;
}

int m, n;

int main(){
    cin >> m >> n;

    m = abs(m), n = abs(n);

    if(m == 0 && n == 0) cout << 0 << '\n';
    else if(m == 0) cout << (n == 1 ? 1 : 2) << '\n';
    else if(n == 0) cout << (m == 1 ? 1 : 2) << '\n';
    else {
        int g = gcd(m, n);
        if(g == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}
