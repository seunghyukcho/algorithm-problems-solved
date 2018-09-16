#include<stdio.h>

unsigned float_i2f(int x) {
    int cnt = 0, exp = 0, x_original = x;
    unsigned ret = 0x0, lmb = (1 << 31);

    if(x == lmb) {
        return 0xcf << 24;
    }
    else {
        if(x < 0) {
            ret |= (1 << 31);
            x = ~x + 1;
        }

        while(lmb != 0 && (lmb & x) == 0) {
            lmb >>= 1;
            cnt++;
        }

        if(lmb != 0x0) {
            cnt = 32 - cnt;
            exp = (126 + cnt) << 23;

            while(cnt > 24) {
                if((x & 1) != 0) return x_original;
                x >>= 1;
                cnt--;
            }

            while(cnt < 24) {
                x <<= 1;
                cnt++;
            }

            x = (~(~x | (1 << 23)));
        }

        return x | ret | exp;
    }
}

int main(){
    int x;

    scanf("%x", &x);
    printf("%x\n", float_i2f(x));

    return 0;
}
