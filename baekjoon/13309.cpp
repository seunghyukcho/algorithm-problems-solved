#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200002;
struct SegmentTree {
    struct Node {
        int s, t, cost;
        Node *left, *right;

        Node(int first, int last): s(first), t(last), cost(0) {
            if(first != last) {
                int mid = (s + t) / 2;
                left = new Node(first, mid);
                right = new Node(mid + 1, last);
            }
        }

        int update(int here, int val) {
            if(here < s || here > t) return cost;
            if(s == t) return cost = val;

            return cost = min(left->update(here, val), right->update(here, val));
        }

        int get(int start, int end) {
            if(start <= s && t <= end) return cost;
            if(end < s || t < start) return 2;

            return min(left->get(start, end), right->get(start, end));
        }
    } *root;

    SegmentTree(int n): root(new Node(1, n)) {}

    void update(int here, int val) { root->update(here, val); }
    int get(int start, int end) { return root->get(start, end); }
};

struct HLD {
    int root = 1, n, parent[MAXN], subtree[MAXN], level[MAXN], sparse[MAXN][100], path[MAXN][2];
    vector<int> child[MAXN];
    vector<pair<int, int> > paths;
    SegmentTree* segments;

    HLD(int num): n(num), segments(new SegmentTree(num)) { paths.push_back({0, 0}); }

    int table(int v, int n) {
        if(sparse[v][n]) return sparse[v][n];

        return sparse[v][n] = (n == 0 ? parent[v] : table(table(v, n - 1), n - 1));
    }

    int findParent(int v, int n) {
        for(int i = 0; (1 << i) <= n; i++)
            if(n & (1 << i)) v = table(v, i);

        return v;
    }

    int LCA(int v1, int v2) {
        if(v1 == v2) return v1;
        if(level[v1] > level[v2]) swap(v1, v2);

        int diff = level[v2] - level[v1];
        v2 = findParent(v2, diff);

        int start = 0, end = level[v1];
        while(start < end) {
            int mid = (start + end) / 2;
            if(findParent(v1, mid) == findParent(v2, mid))
                end = mid;
            else
                start = mid + 1;
        }

        return findParent(v1, start);
    }

    int dfs(int here) {
        subtree[here] = 1;
        for(auto next : child[here]) {
            if(next == parent[here]) continue;
            parent[next] = here;
            level[next] = level[here] + 1;
            subtree[here] += dfs(next);
        }

        return subtree[here];
    }

    void decomposition(int here, int path_idx) {
        path[here][0] = paths.size() - 1, path[here][1] = path_idx;
        if(path_idx == 1) {
            paths.push_back({paths.back().first, here});
            path[here][0]++;
        }
        paths.back().first++;

        int mx = 0, nextchild = 0;

        for(int next : child[here]) {
            if(next == parent[here]) continue;

            if(mx < subtree[next]) {
                mx = subtree[next];
                nextchild = next;
            }
        }

        if(!nextchild) return;
        if(subtree[nextchild] * 2 >= subtree[here]) decomposition(nextchild, path_idx + 1);
        else nextchild = 0;

        for(int next : child[here]) {
            if(next == parent[here] || next == nextchild) continue;
            decomposition(next, 1);
        }
    }

    int get_index(int v) {
        return paths[path[v][0] - 1].first + path[v][1];
    }

    void update(int u, int v, int val) {
        if(v == 1) return;
        if(parent[u] == v) swap(u, v);

        segments->update(get_index(v), val);
    }

    int query(int u, int v) {
        int lca = LCA(u, v);

        return min(query2(lca, u), query2(lca, v));
    }

    int query2(int s, int t) {
        if(s == t) return 2;

        if(path[s][0] == path[t][0]) {
            return segments->get(get_index(s) + 1, get_index(t));
        }

        int top_edge = paths[path[t][0]].second;

        return min(query2(s, parent[top_edge]), segments->get(get_index(top_edge), get_index(t)));
    }

} *hld;

int n, q, p[200002];
bool has_parent[200002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    hld = new HLD(n);
    for(int i = 2; i <= n; i++) {
        cin >> p[i];

        hld->child[i].push_back(p[i]);
        hld->child[p[i]].push_back(i);
    }

    hld->dfs(1);
    hld->decomposition(1, 1);

    for(int i = 2; i <= n; i++) hld->update(p[i], i, 1);

    for(int i = 0; i < q; i++) {
        int b, c, d;
        cin >> b >> c >> d;

        int result = hld->query(b, c);
        cout << (result == 1 ? "YES" : "NO") << '\n';

        if(d == 1) {
            result == 1 ? hld->update(hld->parent[b], b, 0) : hld->update(hld->parent[c], c, 0);
        }
    }
}
