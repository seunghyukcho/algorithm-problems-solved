#include<iostream>
#include<algorithm>

using namespace std;

int a[100002], n, ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int pivot = 1;
    for(int i = 0; i < n; i++){
        while(pivot < n && a[i] >= a[pivot]) pivot++;
        if(pivot == n) break;
        else {
            ans++;
            pivot++;
        }
    }

    cout << ans << '\n';

    return 0;
}
