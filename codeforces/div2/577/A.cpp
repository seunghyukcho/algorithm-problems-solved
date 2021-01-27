#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, score;
string answers[1002];

int main()
{
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> answers[i];

    for(int i = 0; i < m; i++)
    {
        cin >> score;
        int mx = 0;
        vector<int> cnt(30, 0);
        for(int j = 0; j < n; j++) 
        {
            int here = answers[j][i] - 'A';
            mx = max(mx, ++cnt[here]);
        }

        ans += score * mx;
    }

    cout << ans << '\n';
}