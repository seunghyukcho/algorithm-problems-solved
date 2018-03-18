#include<iostream>

using namespace std;

int main(){
    int max = 0;
    int row, col;
    for(int i = 0; i < 81; i++){
        int num;
        cin >> num;
        if(max < num){
            max = num;
            row = i / 9 + 1;
            col = i - (row - 1) * 9 + 1;
        }
    }

    cout << max << '\n' << row << ' ' << col << '\n';

    return 0;
}
