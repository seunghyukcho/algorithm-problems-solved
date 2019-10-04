#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int seg[5000002], n;

int get(int left, int right, int start = 1, int end = 2000000, int idx = 1)
{
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[idx];

    int mid = (start + end) / 2;
    return get(left, right, start, mid, idx * 2) + get(left, right, mid + 1, end, idx * 2 + 1);
}

void update(int pos, int val, int start = 1, int end = 2000000, int idx = 1)
{
    seg[idx] += val;
    if(start == end) return;

    int mid = (start + end) / 2;
    if(pos <= mid) update(pos, val, start, mid, idx * 2);
    else update(pos, val, mid + 1, end, idx * 2 + 1);
}

int kth_element(int k, int start = 1, int end = 2000000, int idx = 1)
{
    if(start == end) return start;

    int mid = (start + end) / 2;
    if(k <= seg[2 * idx]) return kth_element(k, start, mid, idx * 2);
    else return kth_element(k - seg[2 * idx], mid + 1, end, idx * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int t, s;
        cin >> t >> s;

        if(t == 1) update(s, 1);
        else
        {
            int result = kth_element(s);
            cout << result << '\n';
            update(result, -1);
        }
    }
}