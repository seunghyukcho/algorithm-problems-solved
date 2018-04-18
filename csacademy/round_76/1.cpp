#include<iostream>

using namespace std;

int sum_digit(int n){
    int ret = 0;

    while(; n > 0; n /= 10)
        ret += n % 10;

    return ret;
}

int f(int n){
    if(n == 0)
        return 1;
    else
        return 1 + f(n - sum_digit(n));
}

int main(){
    int x;
    cin >> x;

    cout << f(x) << '\n';

    return 0;
}
