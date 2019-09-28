#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define MAX 1000000

using namespace std;

typedef long long ll;

static ll seg[3000002];
static int n, m, k;

ll query1(int start, int end, int left = 1, int right = MAX, int idx = 1)
{
    if(end < left || right < start) return 1;
    if(start <= left && right <= end) return seg[idx];

    int mid = (left + right) / 2;
    return query1(start, end, left, mid, idx * 2) * query1(start, end, mid + 1, right, idx * 2 + 1) % MOD;
}

ll query2(int pos, int val, int left = 1, int right = MAX, int idx = 1)
{
    if(left == right) return seg[idx] = val;

    int mid = (left + right) / 2;
    if(pos <= mid) return seg[idx] = query2(pos, val, left, mid, idx * 2) * seg[2 * idx + 1] % MOD;
    else return seg[idx] = query2(pos, val, mid + 1, right, idx * 2 + 1) * seg[2 * idx] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        query2(i, num);
    }

    for(int i = 0; i < m + k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1) query2(b, c);
        else
        {
            if(b > c) swap(b, c);
            cout << query1(b, c) << '\n';
        }
    }
}