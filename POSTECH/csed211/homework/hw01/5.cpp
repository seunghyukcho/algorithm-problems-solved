#include<stdio.h>

int threefourths(int x) {
    return x - (x >> 2);
}

int main() {
    int x;

    scanf("%x", &x);
    printf("%x %x\n", x / 4 * 3, threefourths(x));

    return 0;
}
