#include<iostream>

using namespace std;

int n, m;

int main(){
    cin >> n >> m;

    for(int i = 1; i <= m - n + 1; i++)
        cout << i + n - 1 << (i % 8 ? ' ' : '\n');

    return 0;
}
