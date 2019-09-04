#include <iostream>
#include <algorithm>

using namespace std;

int b, g, n;

int main()
{
    cin >> b >> g >> n;

    if(b < g) swap(b, g);
    int right = min(g, n), left = n - right;

    cout << min(b - left, right) + 1 << '\n';
}