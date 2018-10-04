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

    vector2 operator*(double r) const {
        return vector2(r * x, r * y);
    }

    vector2 operator-(vector2 v) const {
        return vector2(x - v.x, y - v.y);
    }

    vector2 operator+(vector2 v) const {
        return vector2(x + v.x, y + v.y);
    }

    bool operator<(vector2 v) const {
        return x < v.x && y < v.y;
    }

    bool operator==(vector2 v) const {
        return x == v.x && y == v.y;
    }
};

//positive when b is ccw to a
double ccw(vector2 a, vector2 b){
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a - p, b - p);
}

const double EPSILON = 0.00001;
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x){
    double det = (b - a).cross(d - c);

    if(fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);

    if(ccw(a, b, c) != 0 || b < c || d < a) return false;

    p = max(a, c);
    return true;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b){
    if(b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    if(!lineIntersection(a, b, c, d, p))
    return parallelSegments(a, b, c, d, p);
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d){
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d ,a) * ccw(c, d, b);

    if(ab == 0 && cd == 0){
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
