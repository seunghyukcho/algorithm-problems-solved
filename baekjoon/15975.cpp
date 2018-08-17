#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

long long ans;
int n;
vector<int> P[100002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        P[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        sort(P[i].begin(), P[i].end());

        if(P[i].size() > 1) {
            for(int j = 0; j < P[i].size(); j++) {
                if(j == 0) ans += P[i][j + 1] - P[i][j];
                else if(j == P[i].size() - 1) ans += P[i][j] - P[i][j - 1];
                else ans += min(P[i][j + 1] - P[i][j], P[i][j] - P[i][j - 1]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
