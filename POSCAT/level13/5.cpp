#include<iostream>

using namespace std;

int n;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 3)
            cout << i << ' ';
        else
            cout << 'X' << ' ';
    }

    return 0;
}
