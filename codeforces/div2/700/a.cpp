#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        string s;
        cin >> s;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(i % 2 == 0) cout << (ch == 'a' ? "b" : "a");
            else cout << (ch == 'z' ? "y" : "z");
        }

        cout << '\n';
    }
}
