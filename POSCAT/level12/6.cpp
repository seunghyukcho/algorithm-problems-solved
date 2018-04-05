#include<iostream>

using namespace std;

int n;

int main(){
    cin >> n;

    if(!(n % 400) || (n % 4 == 0 && n % 100 != 0))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
