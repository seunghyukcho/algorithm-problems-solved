#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int t, n, a[2002];
vector<pair<int, int> > ans;

bool solve(map<int, int> &m, int sum) {
    if(m.empty()) return true;

    int biggest = m.rbegin()->first;
    int num = sum - biggest;
    if(m.find(num) == m.end()) return false;
    else {
        ans.push_back({num, biggest});
        m[num]--;
        m[biggest]--;

        if(m[num] == 0) m.erase(num);
        if(m[biggest] == 0) m.erase(biggest);

        return solve(m, biggest);
    }
}

int main() {
    for(cin >> t; t > 0; t--) {
        map<int, int> mapA;
        ans.clear();
        
        cin >> n;
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if(mapA.find(a[i]) == mapA.end()) mapA.insert({a[i], 1});
            else mapA[a[i]]++;
        }
        sort(a, a + 2 * n);

        int biggest = mapA.rbegin()->first;
        for(int i = 0; i < 2 * n - 1; i++) {
            map<int, int> tmpA(mapA);

            ans.push_back({a[i], biggest});

            tmpA[a[i]]--;
            tmpA[biggest]--;

            if(tmpA[a[i]] == 0) tmpA.erase(a[i]);
            if(tmpA[biggest] == 0) tmpA.erase(biggest);
            if(solve(tmpA, biggest)) break;
            else ans.clear();
        }

        if(ans.empty()) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << ans[0].first + ans[0].second << '\n';
            for(auto p : ans) cout << p.first << ' ' << p.second << '\n';
        }
    }
}