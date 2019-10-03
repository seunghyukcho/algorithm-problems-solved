#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input, s;
int lp[200010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(char ch : input)
    {
        s.push_back(ch);
        s.push_back('!');
    }

    int mx = 0, ans = 1;
    for(int i = 1; i < s.size(); i++)
    {
        int r = mx + lp[mx];
        lp[i] = (i <= r ? min(r - i, lp[2 * mx - i]) : 0);
        
        while(1)
        {
            if(i + lp[i] + 1 >= s.size() || i - lp[i] - 1 < 0 || s[i - lp[i] - 1] != s[i + lp[i] + 1]) break;
            lp[i]++;
        }

        if(r < i + lp[i]) mx = i;
        if(s[mx] == '!') ans = max(ans, 2 * ((lp[mx] + 1) / 2));
        else ans = max(ans, 2 * (lp[mx] / 2) + 1);
    }

    cout << ans << '\n';
}