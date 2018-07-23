#include<iostream>
#include<algorithm>

using namespace std;

int n, k, temp[250002];
long long ans;

struct Segment {
    int cost[300000];

    int get(int sum = 0, int start = 0, int end = 65535, int v = 1) {
        //cout << sum << ' ' << start << ' ' << end << '\n';
        if(start == end) return start;

        int h = (start + end) / 2;
        if(sum + cost[2 * v] < (k + 1) / 2) return get(sum + cost[2 * v], h + 1, end, 2 * v + 1);
        else return get(sum, start, h, 2 * v);
    }

    void update(int num, int start = 0, int end = 65535, int v = 1) {
        cost[v]++;

        if(start != end) {
            int h = (start + end) / 2;
            if(num <= h) update(num, start, h, 2 * v);
            else update(num, h + 1, end, 2 * v + 1);
        }
    }

    void del(int num, int start = 0, int end = 65535, int v = 1) {
        cost[v]--;

        if(start != end) {
            int h = (start + end) / 2;
            if(num <= h) del(num, start, h, 2 * v);
            else del(num, h + 1, end, 2 * v + 1);
        }
    }
} T;

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> temp[i];
        T.update(temp[i]);
    }

    ans += T.get();

    for(int j = k + 1; j <= n; j++) {
        cin >> temp[j];
        T.update(temp[j]);
        T.del(temp[j - k]);

        int result = T.get();
        ans += result;
    }

    cout << ans << '\n';

    return 0;
}
