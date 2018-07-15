#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

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

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);

        T.update_range(i, i, num);
    }

    for(scanf("%d", &m); m > 0; m--) {
        int t, a, b, c;
        scanf("%d%d%d", &t, &a, &b);
        if(a > b) swap(a, b);

        if(t == 1) {
            scanf("%d", &c);
            T.update_range(a + 1, b + 1, c);
        } else printf("%d\n", T.get_range(a + 1, b + 1));
    }

    return 0;
}
