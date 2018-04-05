#include<iostream>

using namespace std;

int n, i;

int main(){
    cin >> n;

    for(i = 1; i * i < n; i++){}

    cout << i << '\n';

    return 0;
}
