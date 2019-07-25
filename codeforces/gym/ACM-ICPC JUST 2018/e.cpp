#include<iostream>
#include<algorithm>

using namespace std;

int t, n, board[20][20], D[17][17][65536];

int dp(int r, int c, int state) {
    // cout << r << ' ' << c << ' ' << state << ' ' << D[r][c][state] << '\n';
    if(r >= n) return 0;
    if(c >= n) return dp(r + 1, 0, state);
    if(D[r][c][state] != -1) return D[r][c][state];
    if((state & (1 << c)) > 0) return D[r][c][state] = dp(r, c + 1, state - (1 << c));

    int& ret = D[r][c][state];
    int s1 = dp(r, c + 1, state), s2;

    if(c == 0) s2 = dp(r, c + 2, state | (1 << c) | (1 << (c + 1)));
    else if(c == n - 1) s2 = dp(r + 1, 0, state | (1 << c) | (1 << (c - 1)));
    else s2 = dp(r, c + 2, state | (1 << (c - 1)) | (1 << c) | (1 << (c + 1)));

    s2 += board[r][c];
    // cout << r << ' ' << c << ' ' << state << ' ' << s1 << ' ' << s2 << '\n';
    return ret = max(s1, s2);
}

int main(){
    for(cin >> t; t > 0; t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
                for(int k = 0; k < (1 << n); k++) D[i][j][k] = -1;
            }
        }

        cout << dp(0, 0, 0) << '\n';
    }

    return 0;
}
