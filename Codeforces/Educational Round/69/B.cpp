#include <iostream>

using namespace std;

int n, disks[200002];

int main()
{
    int mx[2] = { 0, 0 };

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> disks[i];
        if(mx[0] < disks[i])
        {
            mx[0] = disks[i];
            mx[1] = i;
        }
    }

    bool flag = true;
    for(int i = 0; flag && i < mx[1]; i++)
    {
        if(disks[i] > disks[i + 1]) flag = false;
    }

    for(int i = mx[1]; flag && i < n - 1; i++)
    {
        if(disks[i] < disks[i + 1]) flag = false;
    }

    cout << (flag ? "YES" : "NO") << '\n';
}