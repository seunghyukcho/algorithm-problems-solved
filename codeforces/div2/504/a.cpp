#include<iostream>
#include<string>

using namespace std;

int n, m;
string s, t;

int main() {
    cin >> n >> m;
    cin >> s >> t;

    int pos = -1;
    for(int i = 0; i < s.size() && pos == -1; i++) {
        if(s[i] == '*') pos = i;
    }

    if(pos == -1) {
        if(s == t) cout << "YES\n";
        else cout << "NO\n";
    } else if(s.size() - 1 > t.size()) {
        cout << "NO\n";
    } else {
        for(int i = 0; i < pos; i++) {
            if(s[i] != t[i]) {
                cout << "NO\n";
                return 0;
            }
        }

        for(int i = pos + 1; i < s.size(); i++) {
            if(s[i] != t[i + t.size() - s.size()]) {
                cout << "NO\n";
                return 0;
            }
        }

        cout << "YES\n";
    }

    return 0;
}
