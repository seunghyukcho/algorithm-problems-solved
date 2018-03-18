#include<iostream>

using namespace std;

int k;

int main(){
    int eight, six;

    cin >> k;
    eight = k / 2;
    six = k % 2;

    if(eight + six > 18)
        cout << -1 << '\n';
    else{
        for(int i = 0; i < eight; i++)
            cout << 8;
        for(int j = 0; j < six; j++)
            cout << 6;
        cout << '\n';
    }

    return 0;
}
