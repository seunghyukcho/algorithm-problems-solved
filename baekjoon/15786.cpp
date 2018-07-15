#include<iostream>
#include<string>

using namespace std;

int n, m;
string pwd;

int main(){
    cin >> n >> m >> pwd;

    for(int i = 0; i < m; i++) {
        string input;
        cin >> input;

        int here = 0;
        for(int i = 0; i < input.size() && here < pwd.size(); i++) {
            if(pwd[here] == input[i]) here++;
        }

        cout << (here == pwd.size() ? "true\n" : "false\n");
    }

    return 0;
}
