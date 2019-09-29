#include <iostream>

using namespace std;

static int a, b, n, w;

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main()
{
    cin >> a >> b >> n >> w;
    int x, y, ans[2] = { 0, 0 };

    for(x = 1, y = n - 1; x < n; x++, y--)
    {
        if(a * x + b * y == w)
        {
            if(ans[0] == 0) ans[0] = x, ans[1] = y;
            else
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    if(ans[0]) cout << ans[0] << ' ' << ans[1] << '\n';
    else cout << -1 << '\n';
}