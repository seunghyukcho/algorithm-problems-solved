#include<bits/stdc++.h>

using namespace std;

const int MAXV = 100002, MAXE = 100002;
struct Tree {
    int n, root, sparse[MAXV][100], level[MAXV], parent[MAXV];
    vector<int> V[MAXV];

    void setEdge(int u, int v) {
        V[u].push_back(v);
        V[v].push_back(u);
    }

    void setRoot(int root) {
        this->root = root;
        level[root] = 0;
        setRootedTree();
    }

    void setRootedTree() {
        queue<int> q;
        q.push(root);

        while(!q.empty()) {
            int here = q.front(); q.pop();

            for(int next : V[here]) {
                if(next != parent[here]) {
                    parent[next] = here;
                    level[next]= level[here] + 1;
                    q.push(next);
                }
            }
        }
    }

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

        if(v1 == v2) return v1;

        int start = 1, end = level[v1];
        while(start < end) {
            int mid = (start + end) / 2;

            int p1 = findParent(v1, mid), p2 = findParent(v2, mid);
            if(p1 == p2)
                end = mid;
            else {
                end -= mid;
                v1 = p1, v2 = p2;
            }
        }

        return findParent(v1, start);
    }
} T;

int m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T.n;
    for(int i = 0; i < T.n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T.setEdge(u, v);
    }
    T.setRoot(1);

    for(cin >> m; m > 0; m--) {
        int u, v;
        cin >> u >> v;

        cout << T.LCA(u, v) << '\n';
    }

    return 0;
}
