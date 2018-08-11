#include<iostream>
#include<queue>

using namespace std;

int n, m, a[102], b[102];
int ans[102][102], row, col;

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        row ^= a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
        col ^= b[i];
    }

    if(row != col) cout << "NO\n";
    else {
        for(long long here = 1; ; here <<= 1) {
            bool check = true;
            queue<int> rows[2], cols[2];

            for(int i = 0; i < n; i++) {
                if(a[i] >= here) check = false;

                int sign = a[i] & here ? 1 : 0;
                rows[sign].push(i);
            }

            for(int i = 0; i < m; i++) {
                if(b[i] >= here) check = false;

                int sign = b[i] & here ? 1 : 0;
                cols[sign].push(i);
            }

            if(check) break;
            while(!rows[1].empty() || !cols[1].empty()) {
                if(rows[1].empty()) {
                    int next_row = rows[0].front(); rows[0].pop();
                    while(!cols[1].empty()) {
                        int next_col = cols[1].front(); cols[1].pop();
                        ans[next_row][next_col] ^= here;
                    }
                } else if(cols[1].empty()) {
                    int next_col = cols[0].front(); cols[0].pop();
                    while(!rows[1].empty()) {
                        int next_row = rows[1].front(); rows[1].pop();
                        ans[next_row][next_col] ^= here;
                    }
                } else {
                    int next_row = rows[1].front(); rows[1].pop();
                    int next_col = cols[1].front(); cols[1].pop();

                    ans[next_row][next_col] ^= here;
                }
            }
        }

        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
