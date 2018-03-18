#include<iostream>

using namespace std;

int gcd(int, int);

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int num1, num2;
        cin >> num1 >> num2;
        cout << num1 * num2 / gcd(num1, num2) << '\n';
    }

    return 0;
}

int gcd(int a, int b){
    if(a == 0)return b;
    else return gcd(b % a, a);
}
