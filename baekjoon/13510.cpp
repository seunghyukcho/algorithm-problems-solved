#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

struct Segment {
    int cost[500002];

    void update(int vertex) {
        cost[vertex] = max(cost[vertex * 2], cost[vertex * 2 + 1]);
    }

    int get(int s, int e, int l = 1, int r = n, int idx = 1) {
        if(s <= l && e <= r) return cost[idx];
        if(e < l || r < s) return 0;

        int mid = (l + r) / 2;
        return max(get(s, e, l, mid, idx * 2), get(s, e, mid + 1, r, idx * 2 + 1));
    }

    void set(int v, int c, int l = 1, int r = n, int idx = 1) {
        if(l == r) {
            cost[idx] = c;
            return;
        }

        int mid = (l + r) / 2;
        if(v <= mid) set(v, c, l, mid, idx * 2);
        else set(v, c, mid + 1, r, idx * 2 + 1);

        update(idx);
    }
};

struct HLD {
    int parent[100002], cost[100002];
    int level[100002], heavy[100002];
    int up[100002], index[100002];

    vector<pair<int, int> > E[100002], V[100002];

    int init(int here = 1, int prev = 1) {
        int sum = 0, maxSize = 0;

        for(auto e : V[here]) {
            int next = e.first;
            int c = e.second;

            if(next == prev) continue;
            level[next] = level[here] + 1;
            parent[next] = here;
            cost[next] = c;

            int s = init(next, here);
            if(maxSize < s) {
                heavy[here] = next;
                maxSize = s;
            }
            sum += s;
        }

        return sum + 1;
    }

    void makeHLD(int here, int& idx, int ancestor) {
        up[here] = ancestor;
        index[here] = idx++;
        if(heavy[here] != 0) {
            makeHLD(heavy[here], idx, ancestor);

            for(auto e : V[here]) {
                int next = e.first;
                if(parent[here] == next) continue;
                makeHLD(next, idx, next);
            }
        }
    }

    int getCost(int u, int v) {
        if(up[u] == up[v]) return T.get()
    }

    int query(int u, int v) {
        int lca = LCA(u, v);

    }
}
