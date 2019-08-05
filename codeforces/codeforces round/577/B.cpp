#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, num, mx;
ll sum;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        mx = max(mx, num);
    }

    cout << (sum % 2 == 0 && sum - mx >= mx ? "YES" : "NO") << '\n';
}