#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int q, n, m, rowSum[50002], colSum[50002];
string row;

int main()
{
    for(cin >> q; q > 0; q--)
    {
        cin >> n >> m;
        vector<vector<char> > board(n, vector<char>(m));
        for(int i = 0; i < n; i++) rowSum[i] = 0;
        for(int i = 0; i < m; i++) colSum[i] = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> row;
            for(int j = 0; j < m; j++) 
            {
                char ch = row[j];
                board[i][j] = ch;
                rowSum[i] += (ch == '.');
                colSum[j] += (ch == '.');
            }
        }

        int ans = 1e9;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int result = rowSum[i] + colSum[j];
                if(board[i][j] == '.') result--;
                // cout << i << ' ' << j << ' ' << rowSum[i] << ' ' << colSum[j] << ' ' << result << '\n';
                ans = min(ans, result);
            }

        cout << ans << '\n';
    }
}