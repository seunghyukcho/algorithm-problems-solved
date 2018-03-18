#include<iostream>

using namespace std;

void print(int n){
    if(n == 1){
        cout << "#\n";
        return;
    }
    for(int i = 0; i < n; i++)cout << '#';
    cout << '\n';
    for(int i = 0; i < n-2; i++){
        cout << '#';
        for(int j = 0; j < n-2; j++)cout << 'J';
        cout << '#' << '\n';
    }
    for(int i = 0; i < n; i++)cout << '#';
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int num;
        cin >> num;
        print(num);
        cout << '\n';
    }

    return 0;
}
