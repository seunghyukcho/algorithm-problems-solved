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

    if(check) cout << ((n >> 1) + (1 << (int)(log2(n) + 1))) << ' ' << 0 << '\n';
    else {
        for(long long x = 2; x <= n; x <<= 1) {
            if((x & n) && !((x >> 1) & n)) {
                cout << (n ^ (x + (x >> 1))) << ' ';
                break;
            }
        }

        for(long long x = 2; x <= n; x <<= 1) {
            if((x & n) && !((x << 1) & n)) {
                cout << (n ^ (x + (x << 1))) << '\n';
                break;
            }
        }
    }

    return 0;
}
