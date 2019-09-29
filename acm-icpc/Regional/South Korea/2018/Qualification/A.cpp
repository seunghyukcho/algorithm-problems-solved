#include <iostream>

using namespace std;

typedef long long ll;

static ll n;

int main()
{
    cin >> n;

    int start = 1;
    while(true)
    {
        ll sum = start + (start + 1) * ((1LL << (start + 1)) - 1);

        if(n <= sum) break;
        start++;
    }

    cout << start << '\n';
}