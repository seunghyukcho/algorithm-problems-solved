#include<iostream>
#include<queue>

using namespace std;

int t, n, k;
long long mod = 1e4;

int main(){
    for(cin >> t; t > 0; t--) {
        cin >> k >> n;

        long long ans = 0;
        long long sum = 0;
        long long A = 1983;
        queue<long long> q;

        for(int i = 0; i < n; i++) {
            long long signal = A % mod + 1;
            q.push(signal); sum += signal;

            while(sum > k) {
                sum -= q.front();
                q.pop();
            }
            if(sum == k) ans++;

            A = (A * 214013 + 2531011) % (1LL << 32);
            //cout << sum << '\n';
        }

        cout << ans << '\n';
    }

    return 0;
}
