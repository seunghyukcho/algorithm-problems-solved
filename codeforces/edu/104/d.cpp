#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;

        int maxA = (int)sqrt(2 * n - 1);
        cout << (maxA + 1) / 2 - 1 << '\n';
    }
}
