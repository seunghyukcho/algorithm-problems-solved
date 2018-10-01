#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXV = 100002, MAXE = 100002;
struct Tree {
    struct Edge {
        int idx, start, end, cost;
    };
    struct Vertex {
        int parent, level;
        vector<int> connected;
    } V[MAXV];

    int n, root, sparse[MAXV][100];
    vector<Edge> E;

    void setEdge(int u, int v, int c) {
        int idx = E.size();
        Edge edge1, edge2;

        edge1.idx = idx, edge2.idx = idx + 1;
        edge1.start = edge2.end = u;
        edge1.end = edge2.start = v;
        edge1.cost = edge2.cost = c;

        V[u].connected.push_back(idx);
        V[v].connected.push_back(idx + 1);
        E.push_back(edge1);
        E.push_back(edge2);
    }

    void setRoot(int root) {
        this->root = root;
        V[root].level = 0;
        setRootedTree();
    }

    void setRootedTree() {
        queue<int> q;
        q.push(root);

        while(!q.empty()) {
            int here = q.front(); q.pop();

            for(auto edge : V[here].connected) {
                int next = E[edge].end;

                if(next != V[here].parent) {
                    V[next].parent = here;
                    V[next].level = V[here].level + 1;
                    q.push(next);
                }
            }
        }
    }

    int table(int v, int n) {
        if(sparse[v][n]) return sparse[v][n];

        return sparse[v][n] = (n == 0 ? V[v].parent : table(table(v, n - 1), n - 1));
    }

    int findParent(int v, int n) {
        for(int i = 0; (1 << i) <= n; i++)
            if(n & (1 << i)) v = table(v, i);

        return v;
    }

    int LCA(int v1, int v2) {
        if(v1 == v2) return v1;
        if(V[v1].level > V[v2].level) swap(v1, v2);

        int diff = V[v2].level - V[v1].level;
        v2 = findParent(v2, diff);

        if(v1 == v2) return v1;

        int start = 1, end = V[v1].level;
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
        T.setEdge(u, v, 1);
    }
    T.setRoot(1);

    for(cin >> m; m > 0; m--) {
        int u, v;
        cin >> u >> v;

        cout << T.LCA(u, v) << '\n';
    }

    return 0;
}
