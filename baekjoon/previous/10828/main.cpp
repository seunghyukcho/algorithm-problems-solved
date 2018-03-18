#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> s;

    for(int i = 0; i < n; i++){
        string ss;
        cin >> ss;
        if(ss == "push"){
            int num;
            cin >> num;
            s.push(num);
        }
        else if(ss == "pop"){
            if(s.empty())cout << "-1" << '\n';
            else{
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(ss == "size"){
            cout << s.size() << '\n';
        }
        else if(ss == "empty"){
            cout << s.empty() << '\n';
        }
        else{
            if(s.empty())cout << "-1" << '\n';
            else{
                cout << s.top() << '\n';
            }
        }
    }

    return 0;
}
