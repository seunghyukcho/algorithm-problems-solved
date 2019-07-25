#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b % a == 0)
        return a;
    return gcd(b % a, a);
}

int n, a, b;

int main(){
    cin >> n >> a >> b;

    int x, y;
    for(x = 0;; x++){
        int num = n - a * x;
        if(num < 0)
            break;
        if(num % b == 0){
            y = num / b;
            break;
        }
    }

    if(n - a * x < 0)
        cout << -1 << '\n';
    else{
        int start_num = 1;
        for(int i = 0; i < x; i++){
            for(int j = 1; j < a; j++)
                cout << start_num + j << ' ';
            cout << start_num << ' ';
            start_num += a;
        }
        for(int j = 0; j < y; j++){
            for(int j = 1; j < b; j++)
                cout << start_num + j << ' ';
            cout << start_num << ' ';
            start_num += b;
        }

        cout << '\n';
    }
    return 0;
}

