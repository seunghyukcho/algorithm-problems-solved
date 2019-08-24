#include <iostream>
#include <algorithm>
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

P arr[300002];
int group[300002];
ll cache[300002];

bool comp1(P p1, P p2)
{
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

bool comp2(P p1, P p2)
{
    return p1.second < p2.second;
}

ll factorial(int n)
{
    ll& ret = cache[n];
    if(ret != 0) return ret;
    if(n == 1) return ret = 1;
    
    return ret = factorial(n - 1) * n % MOD;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    ll ans = factorial(n), cnt1 = 1, cnt2 = 1, cnt3 = 0;
    sort(arr, arr + n, comp1);

    int pivot = 0, gnum = 1;
    while(pivot < n)
    {
        int cnt = 1;
        group[pivot] = gnum++;
        for(int next = pivot + 1; next < n && arr[pivot].first == arr[next].first; next++, cnt++)
            group[next] = group[pivot];
        cnt1 = cnt1 * factorial(cnt) % MOD;
        pivot += cnt;
    }

    bool flag = true;
    for(int i = 0; i < n - 1 && flag; i++)
    {
        if(arr[i].second > arr[i + 1].second)
            flag = false;
    }

    if(flag)
    {
        cnt3 = 1;
        pivot = 0;
        while(pivot < n)
        {
            int cnt = 1;
            for(int next = pivot + 1; next < n && arr[pivot].second == arr[next].second && group[pivot] == group[next]; next++, cnt++);
            cnt3 = cnt3 * factorial(cnt) % MOD;
            pivot += cnt;
        }
    }

    sort(arr, arr + n, comp2);
    pivot = 0;
    while(pivot < n)
    {
        int cnt = 1;
        for(int next = pivot + 1; next < n && arr[pivot].second == arr[next].second; next++, cnt++);
        cnt2 = cnt2 * factorial(cnt) % MOD;
        pivot += cnt;
    }

    // cout << ans << ' ' << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';

    cout << (ans - cnt1 - cnt2 + cnt3 + 2 * MOD) % MOD << '\n';
}