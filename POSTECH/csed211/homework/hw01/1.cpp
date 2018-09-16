#include<stdio.h>

int main() {
    int x, y;
    scanf("%x%x", &x, &y);

    int result = (x & 0xff) + ~(~y | 0xff);
    printf("%x\n", result);

    return 0;
}
