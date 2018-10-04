#include<bits/stdc++.h>

using namespace std;

int n, x, y, mountain[2002], here = 0, ans;
vector<pair<int, int> > tops;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < 2 * n; i++) {
        cin >> mountain[i];
    }
    cin >> x;
    for(int i = 0; i < 2 * n; i++) {
        if(i && i % 2 == 0) {
            if(mountain[i - 1] < x && x <= mountain[i]) y = here - (x - mountain[i - 1]);
            here -= mountain[i] - mountain[i - 1];
        }
        else if(i % 2) {
            if(mountain[i - 1] < x && x <= mountain[i]) y = here + (x - mountain[i - 1]);
            here += mountain[i] - mountain[i - 1];
            tops.push_back({mountain[i], here});
        }
    }

    for(auto top : tops) {
        if(top.first >= x) break;

        double a = ((double)y - top.second) / (x - top.first);
        double b = y - a * x;

        ans = max(ans, (int)ceil(b));
    }

    cout << ans << '\n';
}
