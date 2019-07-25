#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int t, n, a[100002], b[100002];
map<int, int> m;

struct Segment {
    long long value[500000];

    long long get(int start, int end, int left = 1, int right = n, int v = 1) {
        if(start <= left && right <= end) return value[v];
        else if(end < left || right < start) return 0;

        int mid = (left + right) / 2;
        return get(start, end, left, mid, 2 * v) + get(start, end, mid + 1, right, 2 * v + 1);
    }

    void update(int pos, int val, int left = 1, int right = n, int v = 1) {
        value[v] += val;

        //cout << left << ' ' << right << ' ' << v << ' ' << value[v] << '\n';

        if(left != right) {
            int mid = (left + right) / 2;

            if(pos <= mid) update(pos, val, left, mid, 2 * v);
            else update(pos, val, mid + 1, right, 2 * v + 1);
        }
    }
} T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> t; t > 0; t--) {
        long long ans = 0;
        m.clear();

        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            // a[i] = i;
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            //b[i] = n - i + 1;
            m[b[i]] = i;
        }

        for(int i = 1; i <= n; i++) {
            ans += T.get(m[a[i]], n);
            T.update(m[a[i]], 1);
        }

        cout << ans << '\n';

        for(int i = 1; i <= n; i++) T.update(m[a[i]], -1);
    }

    return 0;
}
