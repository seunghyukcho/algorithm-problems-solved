#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n, e, d, ans;
    cin >> n >> d >> e;

    ans = n;
    for(int i = 0; i * d <= n; i++) ans = min(ans, (n - i * d) % (5 * e));

    cout << ans << '\n';
}