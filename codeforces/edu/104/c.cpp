#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;

        vector<vector<int> > ans(n, vector<int>(n, -1));
        for(int i = 0; i < n - 1; i++) {
            int win = 0, tie = 0;
            for(int j = 0; j < i; j++) {
                if(ans[j][i] == -1) win++;
                else if(ans[j][i] == 0) tie++;
            }

            if(tie != (n + 1) % 2) ans[i][i + 1] = 0;
            else if(win < (n - 1) / 2) {
                ans[i][i + 1] = 1;
                win++;
            }

            for(int j = i + 3; j < n && win < (n - 1) / 2; j+=2, win++) ans[i][j] = 1;
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}
