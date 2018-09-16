#include<stdio.h>

typedef unsigned float_bits;

float_bits float_add(float_bits x, float_bits y) {

}

float_bits float_multiply(float_bits x, float_bits y) {

}

int main(){
    float_bits x, y;

    scanf("%x%x", &x, &y);
    printf("%x %x\n", float_add(x, y), float_multiply(x, y));

    return 0;
}
