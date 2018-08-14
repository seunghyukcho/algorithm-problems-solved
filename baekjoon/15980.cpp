#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int n, m, total[2002];
int psum[2002][2002];
string s;
char ch;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ch >> s;
        int p = (ch == 'L' ? -1 : 1);

        for(int j = 1; j <= m; j++) {
            psum[i][j] = psum[i][j - 1] + p * (s[j - 1] - '0');
            total[j] += psum[i][j];
        }
    }

    int ans[2] = {1000000000, -1};
    for(int i = 1; i <= n; i++) {
        int mx = 0;
        for(int j = 1; j <= m; j++) {
            mx = max(mx, abs(total[j] - psum[i][j]));
        }
        
        if(ans[0] > mx) {
            ans[0] = mx;
            ans[1] = i;
        }
    }

    cout << ans[1] << '\n' << ans[0] << '\n';

    return 0;
}
