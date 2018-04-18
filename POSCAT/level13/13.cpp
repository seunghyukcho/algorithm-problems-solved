#include<iostream>

using namespace std;

int n;

int main(){
    cin >> n;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++)
            cout << ' ';
        for(int j = i + 1; j <= n; j++)
            cout << '*';
        cout << '\n';
    }

    return 0;
}
