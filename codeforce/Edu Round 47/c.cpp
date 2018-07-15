#include<iostream>
#include<cmath>

using namespace std;

long long n, m;
int main(){
    cin >> n >> m;

    long long xsum = 0, dsum = 0;
    long long abs1, abs2 = 0;

    abs1 = n * (n - 1) / 2;
    for(int i = 1; i <= n; i++) {
        abs2 += abs(i - (n / 2) - 1);
    }

    for(int i = 0; i < m; i++) {
        long long x, d;
        cin >> x >> d;
        xsum += x;
        if(d > 0) dsum += d * abs1;
        else dsum += d * abs2;
    }

    printf("%.6f\n", xsum + dsum / (double)n);

    return 0;
}
