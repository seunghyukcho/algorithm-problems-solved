#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int n, k, a[300002];
ll ans;

int main()
{
    priority_queue<int> pq;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) pq.push(a[i + 1] - a[i]);

    ans += a[n - 1] - a[0];
    for(; k > 1; k--)
    {
        int t = pq.top(); pq.pop();
        ans -= t;
    }

    cout << ans << '\n';
}