#include<bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    struct Node {
        int cnt;
        long long sum, value;
        Node *left, *right, *parent;
    } *tree;

    void rotate(Node* x) {
        Node* p = x->parent;
        Node* next;

        if(x == p->left) {
            p->left = next = x->right;
            x->right = p;
        }
        else {
            p->right = next = x->left;
            x->left = p;
        }

        x->parent = p->parent;
        p->parent = x;
        if(next) next->parent = p;
        if(x->parent) {
            (p == x->parent->left ? x->parent->left : x->parent->right) = x;
        }
        else tree = x;

        update(x);
        update(p);
    }

    void splay(Node* x) {
        while(x->parent) {
            Node* p = x->parent;
            Node* g = p->parent;

            if(g) rotate((x == p->left) == (p == g->left) ? p : x);
            rotate(x);
        }
    }

    void update(Node* x) {
        x->cnt = 1;
        x->sum = x->value;
        if(x->left) {
            x->cnt += x->left->cnt;
            x->sum += x->left->sum;
        }
        if(x->right) {
            x->cnt += x->right->cnt;
            x->sum += x->right->sum;
        }
    }

    void kth_element(int k) {
        Node* x = tree;
        while(1) {
            while(x->left && x->left->cnt > k) x = x->left;
            if(x->left) k -= x->left->cnt;
            if(!k--) break;
            x = x->right;
        }
        splay(x);
    }

    void initialize(int n) {
        Node* x;

        tree = x = new Node;
        x->left = x->right = x->parent = NULL;
        x->cnt = n;
        x->sum = x->value = 0;
        for(int i = 0; i < n; i++) {
            x->right = new Node;
            x->right->parent = x;
            x = x->right;
            x->left = x->right = NULL;
            x->cnt = n - i;
            x->sum = x->value = 0;
        }
    }

    void add(int v, int val) {
        kth_element(v);
        tree->sum += val;
        tree->value += val;
    }

    void interval(int l, int r) {
        if(l > r) swap(l, r);
        kth_element(l - 1);
        Node* x = tree;
        tree = x->right;
        tree->parent = NULL;
        kth_element(r - l + 1);
        x->right = tree;
        tree->parent = x;
        tree = x;
    }

    long long sum(int l, int r) {
        interval(l, r);
        return tree->right->left->sum;
    }
} T;

int n, m, k, number[1000002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    T.initialize(n + 3);

    for(int i = 0; i <= n + 2; i++) {
        if(i >= 1 && i <= n) cin >> number[i];

        T.add(i, number[i]);
    }

    for(int j = 1; j <= m + k; j++) {
        int u, v, c;
        cin >> u >> v >> c;
        if(u == 1) {
            T.add(v, c - number[v]);
            number[v] = c;
        }
        else cout << T.sum(v, c) << '\n';
    }

}
