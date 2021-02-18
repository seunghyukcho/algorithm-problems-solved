#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;

        vector<int> result(n + 1);
        vector<P> start(n + 2), end(n + 1);

        for(int i = 0; i < n; i++) {
            result[i + 1] = result[i] + (s[i] == '+' ? 1 : -1);
            end[i + 1] = {min(end[i].first, result[i + 1]), max(end[i].second, result[i + 1])};
        }
        
        for(int i = n; i > 0; i--) {
            int here = (s[i - 1] == '+' ? 1 : -1);
            start[i] = {min(start[i + 1].first + here, 0), max(start[i + 1].second + here, 0)};
        }
        
        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;

            P prev = end[l - 1], next = start[r + 1];
            next = {next.first + result[l - 1], next.second + result[l - 1]};

            cout << max(next.second, prev.second) - min(next.first, prev.first) + 1 << '\n';
        }
    }
}
