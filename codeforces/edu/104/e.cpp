#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

void solve(vector<int> &prev, vector<int> &next) {
    int m;
    vector<vector<int> > ban(next.size(), vector<int>());

    cin >> m;
    for(int i = 0; i < m; i++) {
        int xx, yy;
        cin >> xx >> yy;
        ban[yy - 1].push_back(xx);
    }

    vector<P> v;
    for(int i = 0; i < prev.size(); i++) v.push_back({prev[i], i + 1});
    sort(v.begin(), v.end());

    for(int i = 0; i < next.size(); i++) {
        sort(ban[i].begin(), ban[i].end());

        int idx = 0;
        for(; idx < v.size(); idx++) {
            if(!binary_search(ban[i].begin(), ban[i].end(), v[idx].second)) break;
        }

        if(idx == v.size()) next[i] = 1e9;
        else next[i] += v[idx].first;
    }
}

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    vector<int> a(n1), b(n2), c(n3), d(n4);
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];
    for(int i = 0; i < n3; i++) cin >> c[i];
    for(int i = 0; i < n4; i++) cin >> d[i];

    solve(a, b);
    solve(b, c);
    solve(c, d);

    int ans = 1e9;
    for(int e: d) ans = min(ans, e);

    cout << (ans == 1e9 ? -1 : ans) << '\n';
}
