#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i] = -1 * b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += -1 * a[i] * b[i];
    }

    cout << ans << '\n';

    return 0;
}
    
