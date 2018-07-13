#include<iostream>

using namespace std;

long long psum[303][303], n, m, k;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> psum[i][j];
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }

    for(cin >> k; k > 0; k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << psum[x][y] - psum[i - 1][y] - psum[x][j - 1] + psum[i - 1][j - 1] << '\n';
    }

    return 0;
}
