#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) { 
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        bool ans = true;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > d) ans = false;
        }

        if(!ans) {
            for(int i = 0; i < n; i++) 
                for(int j = i + 1; j < n; j++)
                    if(a[i] + a[j] <= d) ans = true;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}
