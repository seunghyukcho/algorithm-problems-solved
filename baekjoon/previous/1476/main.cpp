#include<iostream>

using namespace std;

int main(){
    int e, s, m;
    cin >> e >> s >> m;

    int cnt = 1;
    int f_e = 0, f_s = 0, f_m = 0;
    while(f_e != e - 1 || f_s != s - 1 || f_m != m - 1){
        cnt++;
        f_e = (f_e + 1) % 15;
        f_s = (f_s + 1) % 28;
        f_m = (f_m + 1) % 19;
    }

    cout << cnt << '\n';

    return 0;
}

