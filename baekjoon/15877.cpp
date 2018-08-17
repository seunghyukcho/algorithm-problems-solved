#include<iostream>

using namespace std;

bool D[1002][1002], check[1002][1002];
int a, b;

bool win(int n, int m) {
    if(n == 0 && m == 0) return false;
    if(n < 0 || m < 0) return true;
    if(check[n][m]) return D[n][m];

    check[n][m] = true;
    return D[n][m] = !(win(n - 1, m) && win(n, m - 1) && win(n - 1, m - 3) && win(n - 3, m - 1));
}

int main(){
    cin >> a >> b;

    cout << (win(a, b) ? "Alice" : "Bob") << '\n';

    return 0;
}
