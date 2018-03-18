#include<iostream>

using namespace std;

int compare(int x, int y, int z);
int main(){
    int a[2], b[2], c[2];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> c[0] >> c[1];
    int num1 = compare(a[0], b[0], c[0]);
    int num2 = compare(a[1], b[1], c[1]);
    cout << num1 << ' ' << num2 << '\n';

    return 0;
}

int compare(int x, int y, int z){
    if(x == y)return z;
    else if(x == z)return y;
    else return x;
}
