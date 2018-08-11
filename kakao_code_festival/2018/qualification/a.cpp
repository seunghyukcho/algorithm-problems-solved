#include<iostream>

using namespace std;

int first[6][2] = {1, 500, 3, 300, 6, 200, 10, 50, 15, 30, 21, 10};
int second[5][2] = {1, 512, 3, 256, 7, 128, 15, 64, 31, 32};

int t, a, b;
int main() {
    ios::sync_with_stdio(false);

    for(cin >> t; t > 0; t--) {
        cin >> a >> b;
        int ans = 0;
        for(int i = 0; a && i < 6; i++) {
            if(i == 0 && a == 1) {
                ans += first[i][1];
                break;
            }

            if(first[i][0] >= a) {
                ans += first[i][1];
                break;
            }
        }

        for(int i = 0; b && i < 5; i++) {
            if(i == 0 && b == 1) {
                ans += second[i][1];
                break;
            }

            if(second[i][0] >= b) {
                ans += second[i][1];
                break;
            }
        }

        cout << ans * 10000 << '\n';
    }

    return 0;
}
