#include<bits/stdc++.h>

using namespace std;

struct vector2{
    double x, y;

    vector2() { }

    vector2(double _x, double _y): x(_x), y(_y) { }

    double cross(const vector2& v) const {
        return x * v.y - y * v.x;
    }

    double square_distance(const vector2& v) {
        return pow(x - v.x, 2) + pow(y - v.y, 2);
    }

    vector2 operator-(vector2 v) const{
        return vector2(x - v.x, y - v.y);
    }
};

//positive when b is ccw to a
double ccw(vector2 a, vector2 b){
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a - p, b - p);
}

int n;
vector<vector2> P, st;

bool comp1(vector2 v1, vector2 v2) {
    return v1.x == v2.x ? v1.y < v2.y : v1.x < v2.x;
}

bool comp2(vector2 v1, vector2 v2) {
    vector2 v = P[0];

    double dir = ccw(v, v1, v2);

    return dir == 0 ? v.square_distance(v1) > v.square_distance(v2) : dir > 0;
}

struct PointCloud {
    void convexHull() {
        st.clear();
        sort(P.begin(), P.end(), comp1);
        sort(P.begin() + 1, P.end(), comp2);

        st.push_back(P[0]);
        st.push_back(P[1]);
        st.push_back(P[2]);

        for(int i = 2; i <= n; i++) {
            vector2 p = P[i % n];

            while(st.size() >= 3) {
                int sz = st.size();
                vector2 p1 = st[sz - 1], p2 = st[sz - 2];

                if(ccw(p2, p1, p) <= 0) st.pop_back();
                else break;
            }

            st.push_back(p);
        }
    }

    pair<vector2, vector2> farthestPoint() {
        vector2 v1, v2;
        long long mx = 0;
        int j = 1, sz = st.size();

        if(sz - 1 <= 2) {
            return {st[0], st[1]};
        }

        for(int i = 0; i < sz - 1; i++) {
            vector2 p1 = st[i], p2 = st[(i + 1) % (sz - 1)];
            vector2 q1, q2, q3;

            while(1) {
                q1 = st[j], q2 = st[(j + 1) % (sz - 1)], q3 = st[(j + 2) % (sz - 1)];
                vector2 p = p2 - p1, _q1 = q2 - q1, _q2 = q3 - q2;

                if((ccw(p, _q1) >= 0) ^ (ccw(p, _q2) >= 0)) break;
                j = (j + 1) % (sz - 1);
            }

            if(mx < p1.square_distance(q1)) {
                mx = p1.square_distance(q1);
                v1 = p1;
                v2 = q1;
            }

            if(mx < p1.square_distance(q2)) {
                mx = p1.square_distance(q2);
                v1 = p1;
                v2 = q2;
            }

            if(mx < p1.square_distance(q3)) {
                mx = p1.square_distance(q3);
                v1 = p1;
                v2 = q3;
            }
        }

        return {v1, v2};
    }
} T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    for(cin >> t; t > 0; t--) {
        P.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            P.push_back(vector2(x, y));
        }

        T.convexHull();
        auto result = T.farthestPoint();

        cout << (int)result.first.x << ' ' << (int)result.first.y << ' ' << (int)result.second.x << ' ' << (int)result.second.y << '\n';
    }
}
