#include<stdio.h>

int odd_ones(unsigned x) {
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);

    return x & 1;
}

int main(){
    unsigned x;

    scanf("%x", &x);
    printf("%d\n", odd_ones(x));

    return 0;
}
