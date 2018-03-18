#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int start = 1;
    int flag = 0;
    while(start + 6 * flag + 1 <= n){
        start = start + 6 * flag;
        flag++;
    }

    cout << flag + 1 << '\n';

    return 0;
}
