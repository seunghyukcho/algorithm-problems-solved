#include<iostream>

using namespace std;

int main(){
    int total;
    cin >> total;
    for(int i = 0; i < 9; i++){
        int num;
        cin >> num;
        total -= num;
    }

    cout << total << '\n';

    return 0;
}
