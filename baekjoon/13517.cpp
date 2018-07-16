#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int start, end;
    int value;

    Node(Node* l, Node* r, int s, int e) {
        left = l;
        right = r;
        start = s;
        end = e;
        value = 0;
    }
};

int n, m, sparse[100002][20], level[100002], d[100002];
vector<int> child[100002];
Node* root[100002];

Node* insert(Node* p, int val) {
    Node* newNode = new Node(p->left, p->right, p->start, p->end);

    if(p->start == p->end) {
        newNode->value = p->value + 1;
        return newNode;
    } else {
        int h = (p->start + p->end) / 2;
        if(val <= h) {
            newNode->left = insert(p->left, val);
        } else {
            newNode->right = insert(p->right, val);
        }

        newNode->value = newNode->left->value + newNode->right->value;

        return newNode;
    }
}

int parent(int n, int k) {
    if(n == 1) return 0;
    if(sparse[n][k]) return sparse[n][k];
    return sparse[n][k] = parent(parent(n, k - 1), k - 1);
}

int findparent(int here, int h) {
    for(int i = 0; h > 0; i++, h /= 2) {
        if(h % 2) here = parent(here, i);
    }

    return here;
}

int LCA(int u, int v) {
    if(u == v) {
        return u;
    } else if(level[u] < level[v]) {
        return LCA(u, findparent(v, level[v] - level[u]));
    } else if(level[u] > level[v]) {
        return LCA(findparent(u, level[u] - level[v]), v);
    }

    int start = 1, end = level[u] - 1;
    while(start + 1 < end) {
        int mid = (start + end) / 2;
        int p1 = findparent(u, mid);
        int p2 = findparent(v, mid);

        if(p1 == p2) {
            end = mid;
        } else {
            end -= mid;
            u = p1;
            v = p2;
        }
    }

    int p1 = findparent(u, start);
    int p2 = findparent(v, start);

    if(p1 == p2) return p1;
    else return findparent(u, end);
}

void makeLevel(int here, int prev, int l) {
    level[here] = l;
    root[here] = insert(root[findparent(here, 1)], d[here]);
    for(auto next : child[here]) {
        if(next == prev) continue;
        sparse[next][0] = here;
        makeLevel(next, here, l + 1);
    }
}

int get_range(int start, int end, Node* here) {
    if(start <= here->start && here->end <= end) return here->value;
    else if(end < here->start || here->end < start) return 0;

    return get_range(start, end, here->left) + get_range(start, end, here->right);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n - 1; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        child[s].push_back(e);
        child[e].push_back(s);
    }

    root[0] = new Node(NULL, NULL, 1, 1000000);
    queue<Node*> q;
    q.push(root[0]);
    while(!q.empty()) {
        Node* here = q.front(); q.pop();

        if(here->start == here->end) continue;

        int h = (here->start + here->end) / 2;
        Node* left = new Node(NULL, NULL, here->start, h);
        Node* right = new Node(NULL, NULL, h + 1, here->end);

        here->left = left;
        here->right = right;
        q.push(left); q.push(right);
    }

    makeLevel(1, 1, 1);

    for(scanf("%d", &m); m > 0; m--) {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        int lca = LCA(u, v);

        Node* N1 = root[u];
        Node* N2 = root[v];
        Node* N3 = root[lca];
        Node* N4 = root[findparent(lca, 1)];

        int sum = 0, ans;
        while(1) {
            if(N1->start == N1->end) {
                if(sum + 1 <= k) ans = N1->start;
                break;
            }

            int s = sum + N1->left->value + N2->left->value - N3->left->value - N4->left->value + 1;

            if(s > k) {
                N1 = N1->left;
                N2 = N2->left;
                N3 = N3->left;
                N4 = N4->left;
            } else {
                ans = (N1->start + N1->end) / 2 + 1;
                sum += N1->left->value + N2->left->value - N3->left->value - N4->left->value;

                N1 = N1->right;
                N2 = N2->right;
                N3 = N3->right;
                N4 = N4->right;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
