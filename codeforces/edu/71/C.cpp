#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

string s;

ll cache[200002][2], a, b;
ll dp(int n, int k)
{
    ll& ret = cache[n][k];
    if(ret != 0) return ret;

    if(n == 0)
    {
        if(k == 0) return ret = a + 2 * b;
        else return ret = 2 * a + 3 * b;
    }

    if(s[n] == '1')
    {
        return ret = dp(n - 1, k) + a + 2 * b;
    }
    else
    {
        if(s[n - 1] == '1') 
        {
            if(k == 0) return ret = dp(n - 1, 1) + 2 * a + b;
            else return ret = dp(n - 1, 1) + a + 2 * b;
        }
        else if(k == 1)
            return ret = min(dp(n - 1, 1) + a + 2 * b, dp(n - 1, 0) + 2 * (a + b));
        else
            return ret = min(dp(n - 1, 0) + a + b, dp(n - 1, 1) + 2 * a + b);
    }
    
}

int main()
{
    int t;
    for(cin >> t; t > 0; t--)
    {
        int n;
        cin >> n >> a >> b;
        cin >> s;

        for(int i = 0; i <= n; i++) cache[i][0] = cache[i][1] = 0;
        cout << dp(n - 1, 0) << '\n';
    }
}