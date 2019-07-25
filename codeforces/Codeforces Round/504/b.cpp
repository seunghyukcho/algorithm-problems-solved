#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long n, k;

int main(){
    cin >> n >> k;

    if(k - n >= n) cout << 0 << '\n';
    else {
        long long end = min(n, k - 1);
        long long start = k - end;
        long long mid = (start + end) / 2;

        if(mid * 2 == k) cout << mid - start << '\n';
        else cout << mid - start + 1 << '\n';
    }

    return 0;
}
