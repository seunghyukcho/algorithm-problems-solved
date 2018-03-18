#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> time(n);
    for(int i = 0; i < n; i++)cin >> time[i];
    sort(time.begin(), time.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += time[i] * (5 - i);
    }

    cout << ans << '\n';

    return 0;
}
