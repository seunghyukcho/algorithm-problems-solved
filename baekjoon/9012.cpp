#include<iostream>
#include<string>

using namespace std;

int t, s;

int main(){
    for(cin >> t; t > 0; t--){
        string input;
        bool ans = true;
        s = 0;

        cin >> input;
        for(auto here : input){
            if(here == '(')
                s++;
            else if(here == ')'){
                if(!s){
                    ans = false;
                    break;
                }
                else
                    s--;
            }
        }

        if(s)
            ans = false;
        printf("%s\n", ans ? "YES" : "NO");
    }

    return 0;
}
