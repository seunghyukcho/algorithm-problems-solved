#include<iostream>

using namespace std;

int n;

int main(){
    scanf("%d", &n);

    if(n <= 5)
        printf("-1\n");
    else{
        for(int a = 2; a <= 4; a++)
            printf("1 %d\n", a);
        for(int b = 5; b <= n; b++)
            printf("4 %d\n", b);
    }

    for(int i = 2; i <= n; i++)
        printf("1 %d\n", i);

    return 0;
}
