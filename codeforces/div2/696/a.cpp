#include <iostream>
#include <string>

using namespace std;

int t, n;
string a, b;

int main() {
    for(cin >> t; t > 0; t--) {
        cin >> n >> b;
        a = '1';
        for(int i = 1; i < n; i++) {
            if(a[i - 1] + b[i - 1] - '0' != b[i] + 1) a += '1';
            else a += '0';
        }

        cout << a << '\n';
    }
}