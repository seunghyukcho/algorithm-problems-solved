#include<iostream>

using namespace std;

int t, a, b, d;

int main(){
    for(cin >> t; t > 0; t--) {
        scanf("%d%d%d", &a, &b, &d);
        printf("%.6f\n", (double)d * d / 2);
    }
}
