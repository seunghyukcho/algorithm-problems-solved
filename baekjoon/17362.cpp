#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    n = (n - 1) % 8;
    if(n == 0) cout << 1;
    else if(n == 1 || n == 7) cout << 2;
    else if(n == 2 || n == 6) cout << 3;
    else if(n == 4) cout << 5;
    else cout << 4;
    cout << '\n';
}