#include<iostream>

using namespace std;

int n, q1, q2;

struct Segment {
    long long cost[5000000];
    long long lazy[5000000];

    void propagation(int left, int right, int v) {
        cost[v] += lazy[v] * (right - left + 1);
        if(left != right) {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }

    long long get(int left, int right, int start = 1, int end = n, int v = 1) {
        propagation(start, end, v);
        if(left <= start && end <= right) return cost[v];
        if(right < start || end < left) return 0;

        int mid = (start + end) / 2;
        return get(left, right, start, mid, 2 * v) + get(left, right, mid + 1, end, 2 * v + 1);
    }

    long long update(int left, int right, int value, int start = 1, int end = n, int v = 1) {
        propagation(start, end, v);

        if(left <= start && end <= right) {
            lazy[v] += value;
            propagation(start, end, v);

            return cost[v];
        }
        if(right < start || end < left) return cost[v];

        int mid = (start + end) / 2;
        return cost[v] = update(left, right, value, start, mid, 2 * v) + update(left, right, value, mid + 1, end, 2 * v + 1);
    }
} T;

int main(){
    scanf("%d%d%d", &n, &q1, &q2);

    for(int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);

        T.update(i, i, num);
    }

    for(int i = 0; i < q1 + q2; i++) {
        int c, s, e, l;
        scanf("%d%d%d", &c, &s, &e);

        if(c == 1) printf("%lld\n", T.get(s, e));
        else {
            scanf("%d", &l);

            T.update(s, e, l);
        }
    }

    return 0;
}
