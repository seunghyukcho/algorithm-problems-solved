#include<iostream>

using namespace std;

int n;

int main(){
    cin >> n;

    cout << (n % 2 ? "not even" : "even") << '\n';

    return 0;
}
