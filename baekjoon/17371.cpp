#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x[10002], y[10002];

int main()
{
    int n, ans = -1, mn = 1e9;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)
    {
        int f = 0;
        for(int j = 0; j < n; j++)
        {
            if(j == i) continue;
            f = max(f, (int)pow(x[i] - x[j], 2) + (int)pow(y[i] - y[j], 2));
        }

        if(mn > f) 
        {
            ans = i;
            mn = f;
        }
    }

    cout << x[ans] << ' ' << y[ans] << '\n';
}