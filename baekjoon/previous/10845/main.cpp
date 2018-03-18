#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "push"){
            int num;
            cin >> num;
            q.push(num);
        }
        else if(s == "pop"){
            if(q.empty())cout << "-1" << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(s == "size"){
            cout << q.size() << '\n';
        }
        else if(s == "empty"){
            cout << q.empty() << '\n';
        }
        else if(s == "front"){
            if(s.empty())cout << "-1" << '\n';
            else{
                cout << q.front() << '\n';
            }
        }
        else{
            if(s.empty())cout << "-1" << '\n';
            else{
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}
