#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

long long n, x, y;
long long s[2], t[2];
bool match[2];

int main(){
    srand(time(NULL));
    long long a, b;

    cin >> n;

    a = rand() % n + 1;
    b = rand() % n + 1;

    cout << a << ' ' << b << '\n';

    x = y = n / 2;
    s[0] = s[1] = 1;
    t[0] = t[1] = n;
    cout << x << ' ' << y << '\n';
    fflush(stdout);

    for(int i = 0; i < 100000000; i++){
        int ans;
        //cin >> ans;
        if(x == a && y == b) ans = 0;
        else if(x > a && y > b) ans = 3;
        else if(x < a && y > b) ans = (rand() % 2) * 2 + 1;
        else if(x < a) ans = 1;
        else if(x > a && y < b) ans = (rand() % 2) + 2;
        else if(y < b) ans = 2;

        if(ans == 0) break;

        if(ans == 1) {
            s[0] = x + 1;

            x = (t[0] + s[0]) / 2;
        } else if(ans == 2) {
            s[1] = y + 1;

            y = (t[1] + s[1]) / 2;
        } else {
            bool check = true;
            if(!match[0]) {
                if(y == s[1]) {
                    t[0] = x - 1;
                    check = false;
                }
            }
            if(!match[1]) {
                if(x == s[0]) {
                    t[1] = y - 1;
                    y = (t[1] + s[1]) / 2;
                }
                else y = (y + s[1]) / 2;
            }

            if(check) x = (x + s[0]) / 2;
            else x = (s[0] + t[0]) / 2;
        }

        //cout << x << ' ' << y << '\n';
        fflush(stdout);
        if(s[0] == t[0]) match[0] = true;
        if(s[1] == t[1]) match[1] = true;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
