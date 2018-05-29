#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

int t;
string input;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> input;

        stack<char> s;
        int p1, p2, p3, ans, cnt;
        p1 = p2 = p3 = ans = cnt = 0;

        for(auto ch : input){
            if(ch == '(' || ch == '{' || ch == '[')
                s.push(ch);
            else{
                if(s.empty()){
                    ans = max(ans, cnt);
                    cnt = 0;
                }
                else if(ch == ')' && s.top() != '('){
                    ans = max(ans, cnt);
                    cnt = 0;
                    while(!s.empty())
                        s.pop();
                }
                else if(ch == '}' && s.top() != '{'){
                    ans = max(ans, cnt);
                    cnt = 0;
                    while(!s.empty())
                        s.pop();
                }
                else if(ch == ']' && s.top() != '['){
                    ans = max(ans, cnt);
                    cnt = 0;
                    while(!s.empty())
                        s.pop();
                }
                else{
                    s.pop();
                    cnt += 2;
                }
            }
        }

        ans = max(ans, cnt);

        cout << "Case #" << cs << '\n';
        cout << ans << '\n';
    }

    return 0;
}
