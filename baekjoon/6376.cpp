#include<iostream>

using namespace std;

double fac(int n) {
    if(!n) return 1;

    double ret = 1;

    for(int i = 1; i <= n; i++) ret *= i;

    return ret;
}

int main(){
    printf("n e\n- -----------\n");
    for(int n = 0; n <= 9; n++) {
        double ret = 0;

        for(int i = 0; i <= n; i++) ret += 1 / fac(i);

        cout << n << ' ' << ret << '\n';
    }
}
