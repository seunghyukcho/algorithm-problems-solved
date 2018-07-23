#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, num[100002], psum[100002], mn[1000002];

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];

    psum[n] = mn[n] = num[n];
    for(int i = n - 1; i >= 1; i--) {
        psum[i] = psum[i + 1] + num[i];
        mn[i] = min(num[i], mn[i + 1]);
    }

    double ans = -1;
    vector<int> v;

    for(int k = 2; k < n; k++) {
        double avg = (psum[k] - mn[k]) / (double)(n - k);
        if(ans < avg) {
            v.clear();
            ans = avg;
            v.push_back(k - 1);
        } else if(ans == avg) v.push_back(k - 1);
    }

    for(int output : v) cout << output << '\n';

    return 0;
}
