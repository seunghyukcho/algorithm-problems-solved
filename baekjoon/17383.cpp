#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll t[100002];
bool visited[100002];

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t, t + n, comp);

    ll start = 1, end = t[0];
    while(start < end)
    {
        for(int i = 0; i < n; i++) visited[i] = false;
        ll mid = (start + end) / 2;

        ll sum1 = 0, sum2 = 0;
        bool flag = true;
        int idx;
        for(idx = 0; idx < n && t[idx] > mid; idx++);

        for(int i = 0; i < n && flag; i++)
        {
            if(visited[i]) continue;
            ll here = sum1 + t[i];
            if(t[i] % mid != 0) here += mid - t[i] % mid;

            ll find = (here - sum2) / mid - 1;

            for(int j = 0; j < find && flag; j++)
            {
                if(idx == n) flag = false;
                else visited[idx++] = true;
            }

            sum1 = here - mid;
            sum2 = here;
        }

        if(flag) end = mid;
        else start = mid + 1;
    }

    cout << start << '\n';
}