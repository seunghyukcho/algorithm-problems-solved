#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

static string s, input;
static int lp[4000002];
static ll ans;

int main()
{
    cin >> input;
    ans = input.size();
    for(char ch : input)
    {
        s.push_back(ch);
        s.push_back('!');
    }

    int p = 0;
    for(int i = 1; i < s.size(); i++)
    {
        int r = p + lp[p];
        lp[i] = (r < i ? 0 : min(r - i, lp[2 * p - i]));

        while(i + lp[i] + 1 < s.size() && i - lp[i] - 1 >= 0 && s[i + lp[i] + 1] == s[i - lp[i] - 1])
            lp[i]++;
        if(r < i + lp[i]) p = i;
        if(s[i] == '!') ans += (lp[i] + 1) / 2;
        else ans += lp[i] / 2;
    }

    cout << ans << '\n';
}