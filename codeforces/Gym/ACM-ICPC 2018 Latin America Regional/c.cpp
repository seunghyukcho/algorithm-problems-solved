#include<iostream>
#include<cmath>

using namespace std;

int n, k, seq[10002], cnt[10002], up, down;

int main() {
    int div;

    cin >> k >> n;
    if((n - 1) % k == 0) div = (n - 1) / k;
    else if((n + 1) % k == 0) div = (n + 1) / k;
    else if(n % k == 0) div = n / k;
    else {
        cout << "*" << '\n';
        return 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> seq[i];
        cnt[seq[i]]++;
    }

    for(int i = 1; i <= k; i++) {
        if(abs(div - cnt[i]) > 1) {
            cout << "*" << '\n';
            return 0;
        }

        if(div < cnt[i]) {
            if(up) {
                cout << "*" << '\n';
                return 0;
            }
            up = i;
        }
        else if(div > cnt[i]) {
            if(down) {
                cout << "*" << '\n';
                return 0;
            }
            down = i;
        }
    }

    if(up && down) {
        cout << "-" << up << " +" << down << '\n';
    } else if(up) {
        cout << "-" << up << '\n';
    } else if(down) {
        cout << "+" << down << '\n';
    }

    return 0;
}
