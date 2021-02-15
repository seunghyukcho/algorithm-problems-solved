#include <iostream>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, k;
        cin >> n >> k;

        if(n % 2 == 0) cout << (k - 1) % n + 1 << '\n';
        else cout << ((k - 1) % n + (k - 1) / (n / 2)) % n + 1 << '\n';       
    }
}
