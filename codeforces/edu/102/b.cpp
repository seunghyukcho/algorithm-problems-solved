#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        string s, t;
        cin >> s >> t;

        int sLen = s.size(), tLen = t.size();
        int g = 1;
        for(int i = 2; i <= min(sLen, tLen); i++) {
            if(sLen % i == 0 && tLen % i == 0) g = i;
        }

        int l = sLen * tLen / g;
        string newS, newT;
        for(int i = 0; i < l / sLen; i++) newS += s;
        for(int i = 0; i < l / tLen; i++) newT += t;

        if(newS.compare(newT) == 0) cout << newS << '\n';
        else cout << -1 << '\n';
    }
}
