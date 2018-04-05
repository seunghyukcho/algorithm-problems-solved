#include<iostream>

using namespace std;

int a, b;

int main(){
    cin >> a >> b;

    cout << (a - b >= 0 ? a - b : -1) << '\n';

    return 0;
}
