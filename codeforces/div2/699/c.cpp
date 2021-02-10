#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(n);
        map<int, int> colorIdx;
        map<int, queue<int> > colorDiff;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            colorIdx[b[i]] = i;
            if(a[i] != b[i]) colorDiff[b[i]].push(i);
        }

        int changedIdx = -1;
        vector<int> c(m), ans(m, -1);
        for(int i = 0; i < m; i++) cin >> c[i];
        for(int i = m - 1; i >= 0; i--) {
            if(!colorDiff[c[i]].empty()) {
                ans[i] = colorDiff[c[i]].front();
                colorDiff[c[i]].pop();
                changedIdx = ans[i];
            }
            else if(colorIdx.find(c[i]) != colorIdx.end()) {
                ans[i] = colorIdx[c[i]];
                changedIdx = ans[i];
            }
            else if(changedIdx != -1) {
                ans[i] = changedIdx;
            }
            else {
                break;
            }
        }

        for(auto p: colorDiff) {
            if(!p.second.empty()) {
                ans[0] = -1;
                break;
            }
        }

        if(ans[0] == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            for(auto idx : ans) cout << idx + 1 << ' ';
            cout << '\n';
        }
    }
}
