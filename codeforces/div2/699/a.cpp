#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int px, py;
        string s;
        cin >> px >> py >> s;

        vector<int> cnt(4, 0);
        for(char ch: s) {
            switch(ch) {
                case 'U':
                    cnt[0]++;
                    break;
                case 'D':
                    cnt[1]++;
                    break;
                case 'L':
                    cnt[2]++;
                    break;
                case 'R':
                    cnt[3]++;
                default:
                    break;
            }
        }

        if((px > 0 && cnt[3] < px) || (px < 0 && cnt[2] < -px) || (py > 0 && cnt[0] < py) || (py < 0 && cnt[1] < -py)) {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
}