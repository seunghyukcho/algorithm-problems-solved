#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    for(cin >> t; t > 0; t--)
    {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;

        int ans = 0;
        if(h > c)
        {
            ans += h * min(b / 2, p);
            b -= 2 * min(b / 2, p);
            ans += c * min(b / 2, f);
        }
        else
        {
            ans += c * min(b / 2, f);
            b -= 2 * min(b / 2, f);
            ans += h * min(b / 2, p);
        }
        
        cout << ans << '\n';
    }
}