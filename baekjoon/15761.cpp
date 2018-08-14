#include<iostream>
#include<algorithm>

using namespace std;

int w[100002], n, ans;

bool comp(int n1, int n2) { return n1 > n2; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    sort(w + 1, w + 1 + n, comp);

    for(ans = 1; w[ans] >= ans - 1; ans++);

    cout << ans - 1 << '\n';

    return 0;
}
