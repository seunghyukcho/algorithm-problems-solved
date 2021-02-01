#include <iostream>

using namespace std;

typedef long long ll;

int t, n, k;

bool solve(int num) {
    int remain = k - num;
    remain += k * ((n - 1) / (remain + 1));
    if(remain < n - 1) remain += k;
    ll sum = num * (n - 1LL);
    return sum >= remain;
}

int main() {
    for(cin >> t; t > 0; t--) {
        cin >> n >> k;

        int start = 1, end = k;
        while(start < end) {
            int mid = (start + end) / 2;
            if(solve(mid)) end = mid;
            else start = mid + 1;
        }

        cout << start << '\n';
    }
}