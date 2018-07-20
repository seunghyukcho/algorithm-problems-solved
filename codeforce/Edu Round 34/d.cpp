#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    long double data;
    int idx, idx2;
    int up, down;
};
int n;
long double ans;
Node a[200002];

bool comp1(Node n1, Node n2) { return n1.data < n2.data; }
bool comp2(Node n1, Node n2) { return n1.idx > n2.idx; }
int find_up(long long val) {
    int s = 1, e = n;
    while(s < e) {
        int mid = (s + e) / 2;
        if(a[mid].data > val) e = mid;
        else s = mid + 1;
    }

    return s;
}

struct Segment {
    long double sum[500000];
    int count[500000];

    pair<long double, int> get(int start, int end, int left = 1, int right = n, int v = 1) {
        if(start > end || end < left || right < start) return make_pair(0, 0);
        if(start <= left && right <= end) return make_pair(sum[v], count[v]);

        int h = (left + right) / 2;
        auto result1 = get(start, end, left, h, 2 * v);
        auto result2 = get(start, end, h + 1, right, 2 * v + 1);

        return make_pair(result1.first + result2.first, result1.second + result2.second);
    }

    void update(int pos, int val, int left = 1, int right = n, int v = 1) {
        sum[v] += val;
        count[v] += 1;

        if(left != right) {
            int h = (left + right) / 2;
            if(pos <= h) update(pos, val, left, h, 2 * v);
            else update(pos, val, h + 1, right, 2 * v + 1);
        }
    }
} T;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%Lf", &a[i].data);
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1, comp1);
    for(int i = 1; i <= n; i++) {
        a[i].up = find_up(a[i].data + 1);
        if(a[a[i].up].data <= a[i].data + 1) a[i].up += 1;
        a[i].down = find_up(a[i].data - 2) - 1;
        a[i].idx2 = i;
    }
    sort(a + 1, a + n + 1, comp2);

    for(int i = 1; i <= n; i++) {
        auto result1 = T.get(1, a[i].down);
        auto result2 = T.get(a[i].up, n);

        //cout << a[i].data << ' ' << a[i].idx << ' ' << a[i].idx2 << ' ' << a[i].up << ' ' << a[i].down << '\n';

        long double result = result1.first + result2.first - (result1.second + result2.second) * a[i].data;

        ans += result;
        T.update(a[i].idx2, a[i].data);
    }

    printf("%.0Lf\n", ans);

    return 0;
}
