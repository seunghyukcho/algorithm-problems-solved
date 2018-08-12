#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) cout << i << '\n';

    return 0;
}
