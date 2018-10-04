#include<bits/stdc++.h>

using namespace std;

int n;

struct vector2{
    double x, y;

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

double ccw(vector2 a, vector2 b){
    return a.cross(b);
}

//positive when b is ccw to a
double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a - p, b - p);
}

vector<vector2> P, st;

bool comp1(vector2 v1, vector2 v2) {
    return v1.x == v2.x ? v1.y < v2.y : v1.x < v2.x;
}

bool comp2(vector2 v1, vector2 v2) {
    vector2 v = P[0];

    double dir = ccw(v, v1, v2);

    return dir == 0 ? v.square_distance(v1) > v.square_distance(v2) : dir > 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        vector2 v(0, 0);
        cin >> v.x >> v.y;
        P.push_back(v);
    }

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

    cout << st.size() - 1 << '\n';
}
