#include<stdio.h>

int tsub_ok(int x, int y) {
    int msb1 = (x >> 31) & 1;
    int msb2 = (y >> 31) & 1;
    int msb3 = ((x - y) >> 31) & 1;

    return ((~msb1 | msb2 | msb3) & (msb1 | ~msb2 | ~msb3)) & 1;
}

int main(){
    int x, y;

    scanf("%x%x", &x, &y);
    printf("%d\n", tsub_ok(x, y));

    return 0;
}
