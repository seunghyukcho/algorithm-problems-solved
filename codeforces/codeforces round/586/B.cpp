#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

static int n;
static ll mat[1002][1002];

static int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> mat[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        int n1 = i, n2 = (i + 1) % n, n3 = (i + 2) % n;
        ll p1 = mat[n1][n2], p2 = mat[n1][n3], p3 = mat[n2][n3];

        ll ans = p1 * p2 / p3;
        cout << (int)sqrt(ans) << ' ';
    }

    cout << '\n';

    return 0;
}