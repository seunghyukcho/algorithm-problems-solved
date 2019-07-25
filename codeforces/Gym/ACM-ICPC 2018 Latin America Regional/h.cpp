#include<iostream>
#include<algorithm>

using namespace std;

int a[3], b[3], ans;

int main(){
    for(int i = 0; i < 3; i++) cin >> a[i];
    for(int i = 0; i < 3; i++) {
        cin >> b[i];

        ans += max(0, b[i] - a[i]);
    }

    cout << ans << '\n';

}
