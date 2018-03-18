#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i < k - 1)cin >> v[i];
        else{
            cin >> v[i % k];
            vector<int> v2 = v;
            sort(v2.begin(), v2.end());
            if(k % 2)ans += v2[(k + 1) / 2 - 1];
            else ans += v2[k / 2 - 1];
        }
    }

    cout << ans << '\n';

    return 0;
}
