#include<iostream>
#include<algorithm>

using namespace std;

int arr[10002], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    int m1 = arr[n - 1] * arr[n - 2] * arr[n - 3];
    int m2 = arr[n - 1] * arr[0] * arr[1];
    int m3 = arr[n - 1] * arr[n - 2];
    int m4 = arr[0] * arr[1];

    cout << max(max(m1, m2), max(m3, m4)) << '\n';

    return 0;
}
