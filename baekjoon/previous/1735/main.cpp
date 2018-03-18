#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(a == 0)return b;
    else return gcd(b % a, a);
}

int main(){
    int a1, a2;
    int b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    int up, down;
    up = a1 * b2 + b1 * a2;
    down = a2 * b2;
    int g = gcd(up, down);
    up /= g;
    down /= g;

    cout << up << ' ' << down << '\n';

    return 0;
}
