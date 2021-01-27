#include <iostream>

using namespace std;

int a[4];

bool solve()
{
    int total_sum = 0, sum;
    for(int i = 0; i < 4; i++) total_sum += a[i];

    for(int i = 1; i < (1 << 4); i++)
    {
        sum = 0;
        for(int j = 0; j < 4; j++)
        {
            if(i & (1 << j)) sum += a[j];
        }

        if(sum == total_sum / 2 && total_sum % 2 == 0) return true;
    }

    return false;
}

int main()
{
    for(int i = 0; i < 4; i++) cin >> a[i];
    bool result = solve();

    cout << (result ? "YES" : "NO") << '\n';
}