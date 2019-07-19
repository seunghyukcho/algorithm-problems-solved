#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct Point
{
    int x, y;

    Point() {}

    Point(Point p1, Point p2)
    {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
} P[200002];

typedef Point Vector;
int T, N;
Point base;
vector<Point> hull;

bool operator==(Point& p1, Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool comp1(Point p1, Point p2)
{
    if(p1 == base) return true;
    if(p2 == base) return false;
    p1.y -= base.y, p2.y -= base.y;
    p1.x -= base.x, p2.x -= base.x;

    return atan2(p1.x, p1.y) > atan2(p2.x, p2.y);
}

bool comp2(Point p1, Point p2)
{
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}

ll dist(Point p1, Point p2)
{
    return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

int ccw(Vector v1, Vector v2)
{
    ll result = v1.x * v2.y - v2.x * v1.y;
    if(result > 0) return 1;
    else if(result < 0) return -1;
    else return 0;
}

int main()
{
    for(cin >> T; T > 0; T--)
    {
        hull.clear();
        base.x = 1e9, base.y = 1e9;

        cin >> N;
        for(int i = 1; i <= N; i++) cin >> P[i].x >> P[i].y;

        sort(P + 1, P + N + 1, comp2);
        base = P[1];
        sort(P + 2, P + N + 1, comp1);

        for(int i = 1; i <= N; i++)
        {
            while(hull.size() > 1)
            {
                int idx = hull.size(), dir;
                Vector v1(hull[idx - 2], hull[idx - 1]), v2(hull[idx - 1], P[i]);
                dir = ccw(v1, v2);

                if(dir >= 0) break;
                hull.pop_back();
            }

            hull.push_back(P[i]);
        }

        ll ans[3] = { 0, 0, 0 };
        int idx1_1 = 0, idx2_1 = 1, sz = hull.size();
        while(idx2_1 != 0)
        {
            ll d = dist(hull[idx1_1], hull[idx2_1]);
            if(ans[0] < d)
            {
                ans[0] = d;
                ans[1] = idx1_1, ans[2] = idx2_1;
            }

            int dir, idx1_2 = (idx1_1 + sz - 1) % sz, idx2_2 = (idx2_1 + sz - 1) % sz;
            Vector v1(hull[idx1_2], hull[idx1_1]), v2(hull[idx2_2], hull[idx2_1]);
            dir = ccw(v1, v2);

            if(dir >= 0) idx2_1 = (idx2_1 + 1) % sz;
            else idx1_1 = (idx1_1 + 1) % sz;
        }

        cout << hull[ans[1]].x << ' ' << hull[ans[1]].y << ' ' << hull[ans[2]].x << ' ' << hull[ans[2]].y << '\n';
    }
}
