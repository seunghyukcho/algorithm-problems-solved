#include<stdio.h>

typedef unsigned float_bits;

float_bits float_add(float_bits x, float_bits y) {
    unsigned c1 = 0xff << 23, c2 = 0x7fffff, c;
    int exp1 = x & c1, exp2 = x & c1, exp, diff, e1, e2, e;
    int s1 = x & (1 << 31), s2 = y & (1 << 31), s;
    long long m1 = x & c2, m2 = y & c2, m;
    unsigned ground = 0, round = 0, sticky = 0;

    if(exp1 != c1 && exp2 != c2) {
        if(exp1 != 0x0) e1 = exp1 - 127;
        else e1 = 1 - 127;
        if(exp2 != 0x0) e2 = exp2 - 127;
        else e2 = 1 - 127;

        m1 |= (s1 << 32);
        m2 |= (s2 << 32);

        if(exp1 < exp2) {
            s = s2;
            e = e2;
            diff = e2 - e1;
            m1 >>= diff;
        }
        else {
            s = s1;
            e = e1;
            diff = e1 - e2;
            m2 >>= diff;
        }

        if(s1 != s2) {
            if(diff > 0) m = m2 - m1;
            else m = m1 - m2;
        }
        else m = m1 + m2;

        if(m >= (1 << 25)) {
            while(m >= (1 << 25)) {
                sticky |= (m & 1);
                round = (m & 1);
                m = m >>= 1;
                e++;
            }
            ground = m & 1;

            if(((round & sticky) | (ground & round & ~sticky)) != 0x0) {
                m += 1;
            }
            while(m >= (1 << 25)) {
                m = m >>= 1;
                e++;
            }
        }
        else if(m < (1 << 24) && (m != 0x0 || m != 80000000)) {
            while(m >= (1 << 25)) {
                m = m <<= 1;
                e--;
            }
        }

        unsigned exp = (e == -126) ? 0x0 : e + 127;

        if(e > 0xff) return s | (0x7f800000);
        else return s | (e << 23) | m;
    }
    else {
        if(exp1 > exp2) return s1 | 0x7f800000;
        else return s2 | 0x78f00000;
    }

}

float_bits float_multiply(float_bits x, float_bits y) {
    unsigned c1 = 0xff << 23, c2 = 0x7fffff;
    long long exp1 = x & c1, exp2 = x & c1;

    if(exp1 != c1 && exp2 != c1) {
        unsigned s1 = x & (1 << 31), s2 = y & (1 << 31), s = s1 ^ s2;
        long long m1 = x & c2, m2 = y & c2;
        unsigned ground = 0, round = 0, sticky = 0;

        if(exp1 != 0x0) m1 |= (1 << 24);
        if(exp2 != 0x0) m2 |= (1 << 24);

        long long m = m1 * m2, cnt = 1 << 63, e1, e2, e;
        if(exp1 != 0x0) e1 = (exp1 >> 23) - 127;
        else e1 = 1 - 127;
        if(exp2 != 0x0) e2 = (exp2 >> 23) - 127;
        else e2 = 1 - 127;

        e = (exp1 >> 23) + (exp2 >> 23) - 46;

        while(cnt != 0x0 && (cnt | m) == 0x0) {
            cnt >>= 1;
        }

        if(cnt != 0x0) {
            while(m >= (1 << 25)) {
                sticky |= (m & 1);
                round = (m & 1);
                m = m >>= 1;
                e++;
            }
            ground = m & 1;

            if(((round & sticky) | (ground & round & ~sticky)) != 0x0) {
                m += 1;
            }
            while(m >= (1 << 25)) {
                m = m >>= 1;
                e++;
            }

            while(e < -126) {
                e++;
                m >>= 1;
            }

            unsigned exp = (e == -126) ? 0x0 : e + 127;

            if(e > 0xff) return (s1 ^ s2) | (0x7f800000);
            else return (s1 ^ s2) | (e << 23) | m;
        }
        else {
            return 0x0;
        }
    }
    else return (s1 ^ s2) | (0x7f800000);
}

int main(){
    float_bits x, y;

    scanf("%x%x", &x, &y);
    printf("%x %x\n", float_add(x, y), float_multiply(x, y));

    return 0;
}
