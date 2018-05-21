#include<iostream>

using namespace std;

long long n, H;

long long min(long long a, long long b){
    return a > b ? b : a;
}

int main(){
    cin >> n >> H;

    long long start = 1;
    long long end = min(1500000000, H);

    while(start + 1 < end){
        long long mid = (start + end) / 2;

        long long s = mid * (mid + 1) / 2;
        if(s <= n)
            start = mid;
        else
            end = mid - 1;
    }
    if(end * (end + 1) / 2 <= n)
        start = end;

    long long s = start * (start + 1) / 2;
    long long ans = start + (n - s) / start + ((n - s) % start ? 1 : 0);

    cout << ans << '\n';

    return 0;
}
