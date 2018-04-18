#include<iostream>

using namespace std;

int m;

int main(){
    int i, sum = 0;

    cin >> m;
    for(i = 1; sum < m; i++)
        sum += i;

    cout << i - 1 << endl;

    return 0;
}
