#include<iostream>
#include<cmath>

using namespace std;

long long a, b;
int main(){
    scanf("%lld%lld", &a, &b);
    if(a > b) {
        long long c = b;
        b = a;
        a = c;
    }

    if(a * b < 0) {
        if(abs(a) < abs(b)) a = -a + 1;
        else b = -(b + 1);
    }

    long long n = b - a + 1;
    printf("%lld\n", n * (n + 1) / 2 + n * (a - 1));

    return 0;
}
