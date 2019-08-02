#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
} P[100002];

bool operator<(Point p1, Point p2)
{
    return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}

bool comp(Point p1, Point p2)
{
    return p1.x < p2.x;
}

int dist(Point p1, Point p2)
{
    return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;
    sort(P, P + n, comp);

    set<Point> st = { P[0], P[1] };
    int ans = dist(P[0], P[1]), start = 0;
    for(int i = 2; i < n; i++)
    {
        while(start < i)
        {
            int diff = P[i].x - P[start].x;
            if(diff * diff >= ans) st.erase(P[start++]);
            else break;
        }

        int d = sqrt(ans);
        Point lower = { -100000, P[i].y - d }, upper = { 100000, P[i].y + d };
        auto f1 = st.lower_bound(lower);
        auto f2 = st.upper_bound(upper);

        for(auto f = f1; f != f2; f++)
        {
            if(ans > dist(*f, P[i])) ans = dist(*f, P[i]);
        }

        st.insert(P[i]);
    }

    cout << ans << '\n';
}