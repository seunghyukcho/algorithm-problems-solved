#include<stdio.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
    int c = 0xff << 23;

    if((f & c) != c) {
        if((f & c) == 0x0) {
            int msb = f & (1 << 31);
            f = ((f << 1) >> 2) | msb;
        }
        else {
            int exp = (((f & c) >> 23) - 1) << 23;

            f = ~(~f | c) | exp;
        }
    }

    return f;
}

int main() {
    float_bits x;

    scanf("%x", &x);
    printf("%x %x\n", x, float_half(x));

    return 0;
}
