#include<iostream>
#include<algorithm>

using namespace std;

int a, b, c;

int main(){
    cin >> a >> b >> c;

    cout << max(a, max(b, c)) << '\n';

    return 0;
}
