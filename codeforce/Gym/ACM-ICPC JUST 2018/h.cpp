#include<iostream>
#include<cmath>

using namespace std;

int t, a;

int main(){
    for(cin >> t; t > 0; t--) {
        cin >> a;
        cout << (int)sqrt(a / 6) << '\n';
    }

    return 0;
}
