#include<iostream>

using namespace std;

int main(){
    int max = 0;
    int line;
    for(int i = 1; i <= 9; i++){
        int num;
        cin >> num;
        if(max < num){
            max = num;
            line = i;
        }
    }

    cout << max << '\n' << line << '\n';

    return 0;
}
