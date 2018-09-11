#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, num;

int main(){
    for(cin >> t; t > 0; t--) {
        vector<int> a(10002, 0);
        int ans = 0;

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> num;
            a[num]++;
        }

        for(int i = 1; i <= 10000; i++) {
            ans = max(ans, a[i] + a[i + 1]);
        }

        cout << ans << '\n';
    }

    return 0;
}
