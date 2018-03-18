#include<iostream>

using namespace std;

int main(){
    for(int i = 0; i < 3; i++){
        int num = 0;
        for(int j = 0; j < 4; j++){
            int n;
            cin >> n;
            if(!n)num++;
        }
        if(!num)cout << 'E' << '\n';
        else printf("%c\n", 'A' + num - 1);
    }

    return 0;
}
