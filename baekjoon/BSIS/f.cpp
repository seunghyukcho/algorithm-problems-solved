#include<iostream>
#include<algorithm>

using namespace std;

int n, q, d[500002];
long long pos[500002];

struct Query {
    int t, l, r, idx, ans;
} Q[500002];

bool comp1(Query q1, Query q2) { return q1.t < q2.t; }
bool comp2(Query q1, Query q2) { return q1.idx < q2.idx; }

int main(){
    scanf("%d%d", &n, &q);

    Q[0].t = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        pos[i] = -i;
    }

    for(int i = 1; i <= q; i++) {
        scanf("%d%d%d", &Q[i].t, &Q[i].l, &Q[i].r);
        Q[i].idx = i;
    }

    sort(Q + 1, Q + 1 + q, comp1);
    for(int i = 1; i <= q; i++) {
        long long diff = Q[i].t - Q[i - 1].t;
        if(diff) {
            for(int i = 1; i <= n; i++) pos[i] += diff * d[i];
        }

        for(int i = 1; i <= n; i++)
            if(pos[i] >= Q[i].l && pos[i] <= Q[i].r) Q[i].ans++;

    }

    sort(Q + 1, Q + 1 + q, comp2);
    for(int i = 1; i <= q; i++) printf("%d\n", Q[i].ans);

    return 0;
}
