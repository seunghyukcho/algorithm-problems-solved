#include<iostream>

using namespace std;

int a[1000002], b[1000002], n;
int mod = 1999;

int main(){
    int sum1 = 0, sum2 = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum1 += a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum2 += b[i];
    }

    for(int i = 0; i < n; i++) {
        sum1 += a[i] & (sum2 % mod);
    }

    cout << sum1 % mod << '\n';
}
