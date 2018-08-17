#include<iostream>
#include<algorithm>

using namespace std;

int n, m, D[1001][1001], ans;
char map[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];

            if(map[i][j] == '1') D[i][j] = min(D[i - 1][j], min(D[i][j - 1], D[i - 1][j - 1])) + 1;
            ans = max(ans, D[i][j]);
        }

    cout << ans * ans << '\n';

    return 0;
}
