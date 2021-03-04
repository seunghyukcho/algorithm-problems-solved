#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        string s;
        cin >> s;

        int cnt[3] = {0, 0, 0};
        for(char ch: s) cnt[ch - 'A']++;

        char bracket[3] = {')', ')', ')'};
        bracket[s[0] - 'A'] = '(';

        bool ans = false;
        for(int i = 0; i < 3 && !ans; i++) {
            if(cnt[i] == cnt[(i + 1) % 3] + cnt[(i + 2) % 3]) {
                ans = true;
                if(bracket[i] == '(') bracket[(i + 1) % 3] = bracket[(i + 2) % 3] = ')';
                else {
                    bracket[i] = ')';
                    bracket[(i + 1) % 3] = bracket[(i + 2) % 3] = '(';
                }
            }
        }

        int st = 0;
        for(int i = 0; i < s.size() && ans; i++) {
            char ch = bracket[s[i] - 'A'];
            if(ch == '(') st++;
            else if(st == 0) ans = false;
            else st--;
        }

        if(ans && st == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
