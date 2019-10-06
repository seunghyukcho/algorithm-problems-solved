#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second

using namespace std;

typedef pair<int, int> point;

int N, M, seg[8000][8000], map[1025][1025];

int get_col(int left, int right, int row, int start = 1, int end = N, int idx = 1)
{
    if(left > right) return get_col(right, left, row);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[row][idx];

    int mid = (start + end) / 2;
    return get_col(left, right, row, start, mid, idx * 2) + get_col(left, right, row, mid + 1, end, idx * 2 + 1);
}

int get_row(point p1, point p2, int start = 1, int end = N, int idx = 1)
{
    if(p1.x > p2.x) return get_row(p2, p1);
    if(p2.x < start || end < p1.x) return 0;
    if(p1.x <= start && end <= p2.x) return get_col(p1.y, p2.y, idx);

    int mid = (start + end) / 2;
    return get_row(p1, p2, start, mid, idx * 2) + get_row(p1, p2, mid + 1, end, idx * 2 + 1);
}

void update_col(int pos, int val, int row, int start = 1, int end = N, int idx = 1)
{
    seg[row][idx] += val;
    if(start == end) return;

    int mid = (start + end) / 2;
    if(pos <= mid) update_col(pos, val, row, start, mid, idx * 2);
    else update_col(pos, val, row, mid + 1, end, idx * 2 + 1);
}

void update_row(point p, int val, int start = 1, int end = N, int idx = 1)
{
    update_col(p.y, val, idx);
    if(start == end) return;

    int mid = (start + end) / 2;
    if(p.x <= mid) update_row(p, val, start, mid, idx * 2);
    else update_row(p, val, mid + 1, end, idx * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            update_row({ i, j }, map[i][j]);
        }
    }
    
    for(int i = 0; i < M; i++)
    {
        int w, x1, y1, x2, y2;
        cin >> w;
        if(w == 0)
        {
            cin >> x1 >> y1 >> x2;
            update_row({ x1, y1 }, x2 - map[x1][y1]);
            map[x1][y1] = x2;
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;

            cout << get_row({ x1, y1 }, { x2, y2 }) << '\n';
        }
    }

    return 0;
}