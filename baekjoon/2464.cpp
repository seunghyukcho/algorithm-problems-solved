#include<iostream>
#include<cmath>

using namespace std;

long long n;
int main(){
    cin >> n;

    bool check = true;
    for(long long a = n; a > 0 && check; a /= 2) {
        if(a % 2 == 0) check = false;
    }

    if(check) cout << 0 << ' ' << ((n >> 1) + (1 << (int)(log2(n) + 1))) << '\n';
    else {
        int cnt = n % 2;
        for(long long x = 2; x <= n; x <<= 1) {
            if(x & n) cnt++;
            if((x & n) && !((x >> 1) & n)) {
                long long ans = n & ~x;
                for(long long here = x >> 1; here > 0; here >>= 1) {
                    if(cnt) {
                        ans |= here;
                        cnt--;
                    } else ans &= ~here;
                }

                cout << ans << ' ';
                break;
            }
        }

        cnt = 0;
        for(long long x = 1; x <= n; x <<= 1) {
            if((x & n) && !((x << 1) & n)) {
                long long ans = n | (x << 1);

                for(long long here = 1; here <= x; here <<= 1) {
                    if(cnt) {
                        ans |= here;
                        cnt--;
                    } else ans &= ~here;
                }

                cout << ans << '\n';
                break;
            }
            if(x & n) cnt++;
        }
    }

    return 0;
}
