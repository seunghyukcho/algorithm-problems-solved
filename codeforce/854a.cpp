#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int main(){
    int num;
    int a, b;

    cin >> num;
    a = num - 1;
    b = 1;
    while(a > b){
        a--;
        b++;
    }
    while(1){
        if(gcd(a, b) == 1)
            break;
        a--;
        b++;
    }

    cout << a << ' ' << b << '\n';

    return 0;
}
