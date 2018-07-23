#include<iostream>
#include<vector>

using namespace std;

int n, m;
char board[52][52];
vector<pair<int, int> > ans;

bool check(int r, int c) {
    if(c + 2 <= m && (c == 1 || board[r][c - 1] == '#') && board[r][c + 1] == '.' && board[r][c + 2] == '.') return true;
    if(r + 2 <= n && (r == 1 || board[r - 1][c] == '#') && board[r + 1][c] == '.' && board[r + 2][c] == '.') return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> board[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == '.')
                if(check(i, j)) ans.push_back(make_pair(i, j));
        }

    cout << ans.size() << '\n';
    for(auto output : ans) cout << output.first << ' ' << output.second << '\n';

    return 0;
}
