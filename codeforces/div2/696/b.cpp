#include <iostream>
#include <vector>
#define MAXN 50000

typedef long long ll;

using namespace std;

int t, d;
vector<int> primes;

int main() {
    vector<bool> isPrime(MAXN, true);

    for(int i = 2; i < MAXN; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2; i * j < MAXN; j++) isPrime[i * j] = false;
        }
    }

    for(cin >> t; t > 0; t--) {
        cin >> d;

        ll ans = 1;
        int prev = 1, cnt = 1;
        for(int prime: primes) {
            if(prime - prev >= d) {
                ans *= prime;
                prev = prime;
                cnt++;
            }

            if(cnt == 3) break;
        }

        cout << ans << '\n';
    }

}