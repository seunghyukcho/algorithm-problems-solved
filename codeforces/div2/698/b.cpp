#include <iostream>

using namespace std;

int t, q, d;

bool isPositive(int n, int digit) {
    while(n) {
        if((n % 10) == digit) return true;
        n /= 10;
    }

    return false;
}

int main() {
    for(cin >> t; t > 0; t--) {
        cin >> q >> d;
        for(int i = 0; i < q; i++) {
            int num;
            cin >> num;

            if(num >= d * 10) cout << "YES\n";
            else {
                bool positive = false;
                for(; !positive && num > 0; num -= d) {
                    if(isPositive(num, d)) positive = true;
                }

                cout << (positive ? "YES" : "NO") << '\n';
            }
        }
    }
}