#include<iostream>

using namespace std;

int main(){
    for(int i = 0; i < 3; i++){
        char ch;
        int cnt = 0;
        int num;

        for(int j = 0; j < 4; j++){
            cin >> num;
            cnt += num;
        }

        cnt = 4 - cnt;
        ch = cnt ? 'A' + cnt - 1 : 'E';
        cout << ch << '\n';
    }

    return 0;
}
