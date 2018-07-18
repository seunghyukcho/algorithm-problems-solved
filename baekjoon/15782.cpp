#include<iostream>
#include<vector>

using namespace std;

int seg[100002][2], n, m;
vector<int> child[100002];

struct Segment {
    int cost[2000002], lazy[2000002];

    void update_lazy(int l, int r, int v) {
        if(lazy[v] != 0) {
            cost[v] ^= lazy[v] * ((r - l + 1) % 2);

            if(l != r) {
                lazy[2 * v] ^= lazy[v];
                lazy[2 * v + 1] ^= lazy[v];
            }

            lazy[v] = 0;
        }
    }

    int update_range(int left, int right, int val, int start = 1, int end = n, int v = 1) {
        update_lazy(start, end, v);

        if(left <= start && end <= right) {
            lazy[v] ^= val;

            update_lazy(start, end, v);
            return cost[v];
        }
        if(right < start || end < left) return cost[v];

        int mid = (start + end) / 2;

        return cost[v] = update_range(left, right, val, start, mid, 2 * v) ^ update_range(left, right, val, mid + 1, end, 2 * v + 1);
    }

    int get_range(int left, int right, int start = 1, int end = n, int v = 1) {
        update_lazy(start, end, v);

        if(left <= start && end <= right) return cost[v];
        if(right < start || end < left) return 0;

        int mid = (start + end) / 2;

        return get_range(left, right, start, mid, 2 * v) ^ get_range(left, right, mid + 1, end, 2 * v + 1);
    }
} T;

void make_segment(int here, int& index, int prev) {
    //cout << here << '\n';
    seg[here][0] = index;
    for(auto next : child[here]) {
        if(next == prev) continue;
        make_segment(next, index, here);
    }

    seg[here][1] = index++;
}

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n - 1; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        child[s].push_back(e);
        child[e].push_back(s);
    }

    int idx = 1;
    make_segment(1, idx, 1);

    for(int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        T.update_range(seg[i][1], seg[i][1], num);
    }

    for(int i = 1; i <= m; i++) {
        int query, x, y;
        scanf("%d", &query);
        if(query == 1) {
            scanf("%d", &x);
            printf("%d\n", T.get_range(seg[x][0], seg[x][1]));
        } else {
            scanf("%d%d", &x, &y);
            T.update_range(seg[x][0], seg[x][1], y);
        }
    }

    return 0;
}
