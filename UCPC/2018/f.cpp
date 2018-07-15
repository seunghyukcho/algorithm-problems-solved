#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, seg[200002][2], C, color[200002];
vector<int> child[200002];
long long MOD = 1000000007;

struct Segment {
    vector<int> cost[1000002];

    int get_range(int left, int right, int c, int start = 1, int end = n, int v = 1) {
        //cout << c << ' ' << start << ' ' << end << ' ' << mx[v] << ' ' << mn[v] << '\n';
        if(right < start || left > end) return 0;
        if(left <= start && end <= right) {
            auto pos = upper_bound(cost[v].begin(), cost[v].end(), c);
            //cout << start << ' ' << end << '\n';
            //for(auto print : cost[v]) cout << print << ' ';
            //cout << c << ' ' << pos - cost[v].begin() << '\n';
            return pos - cost[v].begin();
        }

        int mid = (start + end) / 2;
        return get_range(left, right, c, start, mid, 2 * v) + get_range(left, right, c, mid + 1, end, 2 * v + 1);
    }

    void update(int idx, int val, int start = 1, int end = n, int v = 1) {
        if(start <= idx && idx <= end) {
            cost[v].push_back(val);
            //cout << start << ' ' << end << ' ' << mx[v] << ' ' << mn[v] << ' ' << idx << ' ' << val << '\n';

            int mid = (end + start) / 2;

            if(start != end) {
                if(idx <= mid) update(idx, val, start, mid, 2 * v);
                else update(idx, val, mid + 1, end, 2 * v + 1);
            }
        }
    }
} T;

void make_segment(int here, int prev, int& index) {
    seg[here][0] = index;

    for(int next : child[here]) {
        if(next == prev) continue;

        make_segment(next, here, index);
    }

    seg[here][1] = index++;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m >> C;
    for(int i = 1; i <= n; i++) cin >> color[i];
    for(int i = 1; i <= n - 1; i++) {
        int s, e;
        cin >> s >> e;
        child[s].push_back(e);
        child[e].push_back(s);
    }

    int idx = 1;
    make_segment(1, 1, idx);

    int ans = 0;
    for(int i = 1; i <= n; i++) T.update(seg[i][1], color[i]);
    for(int i = 1; i <= 1000002; i++)
        if(!T.cost[i].empty()) sort(T.cost[i].begin(), T.cost[i].end());

    for(int i = 1; i <= m; i++) {
        int v, c;
        cin >> v >> c;

        ans = (ans + T.get_range(seg[v][0], seg[v][1], c) % MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
