#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1999

using namespace std;

typedef long long ll;

int n, a[1000002], b[1000002];

int binary_search(vector<int>& v, int find)
{
    int start = 0, end = v.size() - 1;
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(v[mid] < find) start = mid + 1;
        else if(v[mid] > find) end = mid;
        else return v[mid];
    }

    return v[start];
}

void solve1()
{
    int ans = 0, cntA, cntB;
    for(int i = 0; i < 30; i++)
    {
        cntA = cntB = 0;
        for(int j = 0; j < n; j++)
        {
            cntA += (a[j] & (1 << i)) ? 1 : 0;
            cntB += (b[j] & (1 << i)) ? 1 : 0;
        }

        ans += (cntA % MOD) * (cntB % MOD) * ((1 << i) % MOD) % MOD;
        ans %= MOD;
    }

    cout << ans << ' ';
}

void radixSort(vector<int>& v, int bit)
{
    vector<int> zeros, ones;

    for(int num : v)
    {
        if(num & (1 << bit)) ones.push_back(num);
        else zeros.push_back(num);
    }

    v.clear();
    v.insert(v.end(), zeros.begin(), zeros.end());
    v.insert(v.end(), ones.begin(), ones.end());
}

void solve2()
{
    int ans = 0;
    vector<int> A, B;
    for(int i = 0; i < n; i++) A.push_back(a[i]), B.push_back(b[i]);

    for(int t = 0; t <= 28; t++)
    {
        bool flag = true;
        radixSort(A, t);
        radixSort(B, t);

        int find = binary_search(B, (1 << (t + 1)) - (A[0] % (1 << (t + 1))));
        if(!((find + A[0]) & (1 << t))) flag = false;

        for(int i = 0; flag && i < n; i++)
        {
            if(!((A[i] % (1 << (t + 1)) + B[0]) & (1 << t))) flag = false;
            if(!((A[i] % (1 << (t + 1)) + B[n - 1]) & (1 << t))) flag = false;
        }

        ans += (1 << t) * (flag ? 1 : 0);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    solve1();
    solve2();
}