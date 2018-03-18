#include<iostream>

using namespace std;

int check[10002];

void d(int n){
    if(check[n])return;
    check[n] = 1;
    int num = n;
    int k = n;
    while(k > 0){
        num += k%10;
        k/=10;
    }
    d(num);
}

int main(){
    for(int i = 1; i < 10000; i++){
        if(!check[i]){
            cout << i << '\n';
            d(i);
        }
    }

    return 0;
}
