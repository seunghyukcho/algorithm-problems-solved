#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if(n == 1) cout << 1 << '\n';
    else if(n == 2) cout << 1 << ' ' << 2 << '\n';
    else if(n == 3) cout << 1 << ' ' << 1 << ' ' << 3 << '\n';
    else {
        int n1 = (n / 2) + (n % 2);
        int n2 = floor(log2(n));
        int n3 = n - (n1 + n2);

        for(int i = 0; i < n1; i++) cout << 1 << ' ';
        for(int i = 0; i < n3; i++) cout << 2 << ' ';
        for(int i = 1; i <= n2; i++) cout << (1 << i) << ' ';
        cout << '\n';
    }
}
