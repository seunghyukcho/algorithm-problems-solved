#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int pizza[1002][1002], n, m, row[1002], col[1002];
set<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> pizza[i][j];
            ans += pizza[i][j];

            row[i] = max(row[i], pizza[i][j]);
            col[j] = max(col[j], pizza[i][j]);
        }
    }

    for(int i = 0; i < n; i++) st.insert(row[i]);
    for(int i = 0; i < m; i++) st.insert(col[i]);

    for(auto here : st) {
        ans -= here;
    }

    cout << ans << '\n';

    return 0;
}
