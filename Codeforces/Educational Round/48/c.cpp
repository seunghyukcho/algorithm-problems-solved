#include<iostream>

using namespace std;

int n;
long long a[1000002], b[1000002];
long long psuma[1000002], psumb[1000002];
long long ppsuma[1000002], ppsumb[1000002], rppsuma[1000002], rppsumb[1000002];

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psuma[i] = a[i] + psuma[i - 1];
        ppsuma[i] = i * a[i] + ppsuma[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        psumb[i] = b[i] + psumb[i - 1];
        ppsumb[i] = i * b[i] + ppsumb[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        rppsuma[n - i + 1] = i * a[n - i + 1] + rppsuma[n - i + 2];
        rppsumb[n - i + 1] = i * b[n - i + 1] + rppsumb[n - i + 2];
    }

    long long sum = 0;
    long long ans = 0;

    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            long long up = ppsuma[n] - ppsuma[i - 1] - i * (psuma[n] - psuma[i - 1]);
            long long down = rppsumb[n] - rppsumb[i - 1] + (n + i - 2) * (psumb[n] - psumb[i - 1]);
            ans = max(ans, sum + up + down);

            sum += a[i] * 4 * (i - 1) + b[i] * 4 * i - 3;
        } else {
            long long up = rppsuma[n] - rppsuma[i - 1] - (n + i - 2) * (psuma[n] - psuma[i - 1]);
            long long down = rppsumb[n] - rppsumb[i - 1] + i * (psumb[n] - psumb[i - 1]); 
            ans = max(ans, sum + up + down);

            sum += a[i] * 4 * (i - 1) + b[i] * 4 * i - 3;
        }
    }
}
