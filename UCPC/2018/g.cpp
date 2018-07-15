#include<iostream>
#include<string>

using namespace std;

int ans = 0;
char character[4] = {'U', 'C', 'P', 'C'};

int main(){
    string s;
    getline(cin, s, '\n');

    for(auto ch : s) {
        if(ch == character[ans]) ans++;
        if(ans == 4) break;
    }

    if(ans == 4) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";

    return 0;
}
