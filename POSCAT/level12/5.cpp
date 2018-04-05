#include<iostream>

using namespace std;

int a, b;
char ch;

int main(){
    int ans;
    cin >> a >> ch >> b;

    if(ch == '+')
        ans = a + b;
    else if(ch == '-')
        ans = a - b;
    else if(ch == '*')
        ans = a * b;
    else if(ch == '/')
        ans = a / b;

    cout << ans << '\n';

    return 0;
}
