#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static int lp[1000002], M;
static string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> M;
    reverse(s.begin(), s.end());

    int l = 0, r = 0;
    lp[0] = s.size();
    for(int i = 1; i < s.size(); i++)
    {
        lp[i] = (r < i ? 0 : min(lp[i - l], r - i + 1));

        while(i + lp[i] < s.size() && s[lp[i]] == s[i + lp[i]]) lp[i]++;
        if(lp[i] != 0 && i + lp[i] - 1 > r) l = i, r = i + lp[i] - 1;
    }

    for(int i = 0; i < M; i++)
    {
        int query;
        cin >> query;

        cout << lp[s.size() - query] << '\n';
    }

    return 0;
}