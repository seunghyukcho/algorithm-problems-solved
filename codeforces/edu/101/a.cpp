#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        string s;
        cin >> s;
        
        if(s.size() % 2 || s[0] == ')' || s[s.size() - 1] == '(') cout << "NO\n";
        else cout << "YES\n";
    }
}
