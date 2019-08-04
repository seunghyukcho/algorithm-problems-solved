#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check(int n)
{
    if(n == 0 || n == 1) return true;
    return (n % 2 == 0) && check(n / 2);
}

void solve(int n, int total)
{
    if(check(n)) 
    {
        int i;
        for(i = 0; i < n; i++) cout << '#';
        for(; i < total; i++) cout << '.';
        return;
    }
    int left = (n + 1) / 2, right = n / 2;
    int i;
    for(i = 1; i <= right; i *= 2);
    left = min(total / 2, left + right - i / 2);
    right = n - left;
    solve(left, total / 2);
    solve(right, total / 2);
}

int main()
{
    int n, total = 1;
    cin >> n;

    while(total < n) total *= 2;
    solve(n, total);
    cout << '\n';
}