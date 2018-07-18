#include<iostream>
#include<algorithm>

using namespace std;

int n, d;

struct Segment {
    long long cost[500002];

    void update(int pos, long long val, int left = 0, int right = n, int v = 1) {
        cost[v] = max(cost[v], val);

        if(left == right) return;
        int h = (left + right) / 2;
        if(pos <= h) update(pos, val, left, h, 2 * v);
        else update(pos, val, h + 1, right, 2 * v + 1);
    }

    long long get(int start, int end, int left = 0, int right = n, int v = 1) {
        if(start <= left && right <= end) return cost[v];
        if(end < left || right < start) return -1e9;

        int h = (left + right) / 2;
        return max(get(start, end, left, h, 2 * v), get(start, end, h + 1, right, 2 * v + 1));
    }
} T;

int main(){
    cin >> n >> d;

    for(int i = 0; i < 500002; i++) T.cost[i] = -1e9;
    T.update(0, 0);
    
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        long long result = T.get(max(0, i - d), i - 1);
        T.update(i, result + num);
    }

    cout << T.get(1, n) << '\n';

    return 0;
}
