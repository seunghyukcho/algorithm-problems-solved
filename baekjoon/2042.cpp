#include<bits/stdc++.h>

using namespace std;

struct SegmentTree {
    struct Node {
        int s, t;
        long long cost;
        Node *left, *right;

        Node(int first, int last): s(first), t(last), cost(0) {
            if(first != last) {
                int mid = (s + t) / 2;
                left = new Node(first, mid);
                right = new Node(mid + 1, last);
            }
        }

        long long update(int here, int val) {
            if(here < s || here > t) return cost;
            if(s == t) return cost = val;

            return cost = left->update(here, val) + right->update(here, val);
        }

        long long get(int start, int end) {
            if(start <= s && t <= end) return cost;
            if(end < s || t < start) return 0;

            return left->get(start, end) + right->get(start, end);
        }
    } *root;

    SegmentTree(int n): root(new Node(1, n)) {}

    void update(int here, int val) { root->update(here, val); }
    long long get(int start, int end) { return root->get(start, end); }
} *T;

int n, m, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    T = new SegmentTree(n);
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        T->update(i, num);
    }

    for(int i = 1; i <= m + k; i++) {
        int p, s, e;
        cin >> p >> s >> e;
        if(p == 1) T->update(s, e);
        else cout << T->get(s, e) << '\n';
    }
}
