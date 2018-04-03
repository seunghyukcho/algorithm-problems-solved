#include<iostream>
#include<cmath>

using namespace std;

int n, a[100002];
bool check[100002];

void gen_check(int num){
    for(int i = 2; i < sqrt(num); i++)
        if(num % i == 0 && !check[i]){
            for(int j = 1; j * i <= 1e5; j++)
                check[j * i] = true;
        }
    if(!check[num])
        for(int j = 1; j * num <= 1e5; j++)
            check[j * num] = true;
}

int main(){
    bool lex = false;
    int num;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++){
        if(lex){
            for(num = a[i] - 1; check[num]; num--){}
            printf("%d ", num);
            gen_check(num);
        }
        else{
            if(check[a[i]]){
                for(num = a[i]; check[num]; num++){}
                printf("%d ", num);
                gen_check(num);
                lex = true;
            }
            else{
                printf("%d ", a[i]);
                gen_check(a[i]);
            }
        }
    }
    printf("\n");

    return 0;
}
