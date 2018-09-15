#include<stdio.h>

unsigned rotate_left(unsigned x, int n) {
    int l = x >> (32 - n);
    int r = (x << n);

    return l + r;
}

int main() {
    unsigned x;
    int n;

    scanf("%x%d", &x, &n);
    printf("%x\n", rotate_left(x, n));

    return 0;
}
