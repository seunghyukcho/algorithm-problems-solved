#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, start[3002], sz;
vector<int> c[3002];
long long ans, here;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int vote, price;
        cin >> vote >> price;
        c[vote].push_back(price);
    }

    for(int i = 1; i <= m; i++) {
        sort(c[i].begin(), c[i].end());
        start[i] = 0;
    }

    sz = c[1].size();
    for(int t = 1; t <= n; t++) {
        //cout << here << ' ' << sz << ' ' << ans << '\n';
        int mx = 0;
        long long newans = here;
        priority_queue<int> pq;
        priority_queue<pair<int, int> > pq2;

        for(int i = 2; i <= m; i++) {
            mx = mx > c[i].size() - start[i] ? mx : c[i].size() - start[i];
            for(int j = start[i]; j < c[i].size(); j++) pq.push(-c[i][j]);
        }

        if(mx < sz) {
            ans = min(ans, newans);
            break;
        }

        int flag = sz;
        while(!pq.empty() && flag <= mx) {
            newans += -pq.top(); pq.pop();
            flag++;
        }

        ans = (t == 1) ? newans : min(ans, newans);

        for(int i = 2; i <= m; i++) {
            if(c[i].size() - start[i] == mx) {
                pq2.push({-c[i][start[i]], i});
            }
        }

        while(sz <= mx && !pq2.empty()) {
            here += -pq2.top().first;
            start[pq2.top().second]++;
            pq2.pop();
            sz++;
        }

        if(mx < sz) {
            ans = min(ans, newans);
            break;
        }

        if(here >= ans) break;
    }

    cout << ans << '\n';

    return 0;
}
