#include<iostream>
#include<string>

using namespace std;

int n, t;
string s;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case #" << cs << ": ";
        cin >> s;

        int start = -1;
        for(int i = 0; i < s.size() - 1; i++){
            bool check = false;
            start = i;
            if(s[i] < s[i + 1])
                continue;
            else if(s[i] == s[i + 1]){
                while(i < s.size() - 1 && s[i] == s[i + 1])
                    i++;
            }

            if(i < s.size() - 1 && s[i] > s[i + 1]){
                s[start]--;
                for(int i = start + 1; i < s.size(); i++)
                    s[i] = '9';
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0')
                continue;
            cout << s[i];
        }

        cout << '\n';
    }

    return 0;
}
