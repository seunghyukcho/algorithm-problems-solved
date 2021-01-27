#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k, arr[200002];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int start = arr[n / 2], end = 2000000001;
    while(start < end)
    {
        ll mid = ((ll)start + end) / 2;
        ll penalty = 0;

        for(int i = n / 2; i < n; i++) penalty += max(0LL, mid - arr[i]);
        
        if(penalty <= k) start = mid + 1;
        else end = mid;
    }

    cout << start - 1 << '\n';
}