#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

int n, m, k, a[300002];
ll ans, cache[300002];

ll dp(int idx)
{
    ll& ret = cache[idx];
    if(ret != LLONG_MIN) return ret;
    if(idx == n - 1) return ret = a[idx] - k;

    ll sum = 0;
    for(int i = 0; i < n && i < m; i++)
    {
        sum += a[idx + i];
        ret = max(ret, sum - k);
    }

    if(idx + m >= n) return ret;
    else return ret = max(ret, sum - k + dp(idx + m));
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cache[i] = LLONG_MIN;
    }

    for(int i = 0; i < n; i++) 
    {
        // cout << i << ' ' << dp(i) << '\n';
        ans = max(ans, dp(i));
    }

    cout << ans << '\n';
}