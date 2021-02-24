#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
string s, t;

int main() {
    cin >> n >> m >> s >> t;
    map<char, vector<int> > indices;

    for(int i = 0; i < n; i++) indices[s[i]].push_back(i);
    vector<int> ans;
    int here = m - 1;
    for(int i = n - 1; i >= 0 && here >= 0; i--) {
        if(s[i] == t[here]) {
            ans.push_back(i);
            here--;
        }
    }
    for(auto p: indices) reverse(p.second.begin(), p.second.end());

    int mx = 0;
    here = -1;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < m; i++) {
        auto p = upper_bound(indices[t[i]].begin(), indices[t[i]].end(), here);
        if(p != indices[t[i]].end()) ans[i] = *p;
        here = ans[i];
        if(i > 0) mx = max(mx, ans[i] - ans[i - 1]);
        if(i < m - 1) mx = max(mx, ans[i + 1] - ans[i]);
    }

    cout << mx << '\n';
}
