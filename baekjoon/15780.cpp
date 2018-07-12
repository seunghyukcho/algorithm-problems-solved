#include<iostream>

using namespace std;

int main(){
    int n, k, sum = 0;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        int a;
        cin >> a;

        sum += (a / 2) + (a % 2);
    }

    cout << (sum >= n ? "YES" : "NO") << '\n';

    return 0;
}
