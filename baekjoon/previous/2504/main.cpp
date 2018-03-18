#include<iostream>
#include<string>

using namespace std;

int check;


int main(){
    string s;
    cin >> s;
    int ans = 0;
    int mul = 1;
    int num1 = 0, num2 = 0;
    for(auto i = s.begin(); i < s.end();i++){
        while(i != s.end() && (*i == '(' || *i == '[')){
            if(*i == '('){
                num1++;
                mul *= 2;
            }
            else{
                num2++;
                mul *= 3;
            }
            i++;
        }
        if(*i == ')'){
            if(i != s.begin() && *(i-1) == '(')ans += mul;
            else if(i != s.begin() && (*(i-1) == '[' || num1 <= 0)){
                ans = 0;
                break;
            }
            num1--;
            mul /= 2;
        }
        else{
            if(i != s.begin() && *(i-1) == '[')ans += mul;
            else if(i != s.begin() && (*(i-1) == '(' || num2 <= 0)){
                ans = 0;
                break;
            }
            num2--;
            mul /= 3;
        }
        
    }
    if(num1 || num2)ans = 0;
    cout << ans << '\n';
    return 0;
}
