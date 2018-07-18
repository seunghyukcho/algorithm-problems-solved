#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct Point {
    long long x, y;
} P[100002];

int n;
vector<Point> st;

bool comp1(Point p1, Point p2) {
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

bool comp2(Point p1, Point p2) {
    long long x1 = p1.x - P[0].x;
    long long y1 = p1.y - P[0].y;
    long long x2 = p2.x - P[0].x;
    long long y2 = p2.y - P[0].y;

    double theta1 = atan2(x1, y1);
    double theta2 = atan2(x2, y2);

    if(theta1 == theta2) return pow(p1.x - P[0].x, 2) + pow(p1.y - P[0].y, 2) < pow(p2.x - P[0].x, 2) + pow(p2.y - P[0].y, 2);

    return theta1 > theta2;
}

bool ccw(Point p1, Point p2, Point p3) {
    long long sum1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    long long sum2 = p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;

    return sum1 - sum2 > 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long x, y;
        scanf("%lld%lld", &x, &y);

        P[i] = {x, y};
    }

    sort(P, P + n, comp1);
    sort(P + 1, P + n, comp2);

    st.push_back(P[0]); st.push_back(P[1]);

    for(int i = 2; i < n; i++) {
        while(st.size() >= 2 && !ccw(st[st.size() - 2], st[st.size() - 1], P[i])) {
            st.pop_back();
        }
        st.push_back(P[i]);
    }

    printf("%d\n", st.size());

    return 0;
}
