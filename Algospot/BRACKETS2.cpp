#include<iostream>
#include<string>
#include<map>

using namespace std;

map<char, int> m;
int c;

void bracket_match(string input){
    int s[10002]; int top = 0;

    for(auto ch : input){
        int here = m[ch];

        if(here >= 3){
            if(top == 0 || s[top - 1] != here - 3){
                printf("NO\n");
                return;
            }
            top--;
        } else {
            s[top++] = here;
        }
    }

    if(top) printf("NO\n");
    else printf("YES\n");
}

int main(){
    m['('] = 0; m[')'] = 3;
    m['{'] = 1; m['}'] = 4;
    m['['] = 2; m[']'] = 5;

    for(cin >> c; c > 0; c--){
        string s;

        cin >> s;
        bracket_match(s);
    }

    return 0;
}
