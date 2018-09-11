#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>

using namespace std;

int n, q, original[200002];
pair<int, int> seg[200002];

struct Segment {
    int cost[1000000];
    int lazy[1000000];

    void propagation(int left, int right, int v) {
        cost[v] = max(cost[v], lazy[v]);
        if(left != right) {
            lazy[2 * v] = max(lazy[2 * v], lazy[v]);
            lazy[2 * v + 1] = max(lazy[2 * v + 1], lazy[v]);
        }
        lazy[v] = 0;
    }

    int get(int left, int right, int start = 1, int end = n, int v = 1) {
        propagation(start, end, v);
        if(left <= start && end <= right) return cost[v];
        if(right < start || end < left) return 0;

        int mid = (start + end) / 2;
        return max(get(left, right, start, mid, 2 * v), get(left, right, mid + 1, end, 2 * v + 1));
    }

    int update(int left, int right, int value, int start = 1, int end = n, int v = 1) {
        propagation(start, end, v);

        if(left <= start && end <= right) {
            lazy[v] = max(lazy[v], value);
            propagation(start, end, v);

            return cost[v];
        }
        if(right < start || end < left) return cost[v];

        int mid = (start + end) / 2;
        return cost[v] = max(update(left, right, value, start, mid, 2 * v), update(left, right, value, mid + 1, end, 2 * v + 1));
    }
} T;

int get_val(int x) {
    if(x < 1 || x > n) return 0;
    else return original[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> original[i];
        //original[i] = i;
        if(seg[original[i]].first == 0) seg[original[i]].first = i;
        else seg[original[i]].first = min(seg[original[i]].first, i);

        seg[original[i]].second = max(seg[original[i]].second, i);
    }

    for(int i = 1; i <= q; i++) {
        //cout << i << ' ' << seg[i].first << ' ' << seg[i].second << '\n';
        if(seg[i].first) T.update(seg[i].first, seg[i].second, i);
    }

    bool check = (seg[q].first != 0 ? true : false);
    for(int i = 1; i <= n; i++) {
        int here = T.get(i, i);
        if(original[i] != 0 && original[i] != here) {
            cout << "NO\n";
            return 0;
        }
        if(original[i] == 0) {
            if(!check) {
                original[i] = q;
                check = true;
            }
            else if(here != 0) original[i] = here;
            else {
                int mx = max(get_val(i - 1), get_val(i + 1));

                if(mx != 0) original[i] = mx;
                else {
                    for(int j = 1; mx == 0; j++) {
                        mx = get_val(i + j);
                    }
                    original[i] = mx;
                }
            }
        }
    }

    if(!check) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << original[i] << ' ';
        cout << '\n';
    }

    return 0;
}
