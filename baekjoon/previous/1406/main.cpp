#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    list<char> edit(s.begin(), s.end());

    auto it = edit.end();
    
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        if(ch == 'L'){
            if(it != edit.begin())it--;
        }
        else if(ch == 'D'){
            if(it != edit.end())it++;
        }
        else if(ch == 'B'){
            auto temp = it;
            if(temp != edit.begin()){
                it--;
                edit.erase(it);
                it = temp;
            }
        }
        else if(ch == 'P'){
            char c;
            cin >> c;
            auto temp = it;
            edit.insert(temp, c);
        }
    }

    for(auto j : edit){
        cout << j;
    }

    cout << '\n';

    return 0;
}
