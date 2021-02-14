#include <iostream>
#include <algorithm>

using namespace std;

int solve(int a, int b) {
    if(a == 0) return 0;
    else return 1 + solve(a / b, b);
}

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int a, b;
        cin >> a >> b;

        bool isOne = (b == 1);
        if(isOne) b += 1;
        
        int ans = 40;
        for(int i = 0; i < 40; i++) {
            ans = min(ans, solve(a, b + i) + i);
        }

        cout << ans + isOne << '\n';
    }
}
