#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string a;

int main(){
    cin >> a;
    
    cout << a;
    reverse(a.begin(), a.end());
    cout << a << '\n';

    return 0;
}
