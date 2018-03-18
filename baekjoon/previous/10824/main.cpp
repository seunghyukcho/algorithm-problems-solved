#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    long long int ans = 0;
    string s1(a + b);
    string s2(c + d);
    ans += stoll(s1);
    ans += stoll(s2);

    cout << ans << '\n';

    return 0;
}
