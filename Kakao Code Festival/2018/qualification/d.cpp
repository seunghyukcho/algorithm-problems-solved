#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point {
    int x, y;
    int idx, x_index, y_index;
} P[250002];

int N, Q;

struct Segment {
    int cost[250002];

    int get(int start, int end, int left = 1, int right = N - 1, int v = 1) {
        if(start <= left && end <= right) return cost[v];
        if(end < left || right < start) return 2000000000 + 1;

        int mid = (left + right) / 2;
        return min(get(start, end, left, mid, 2 * v), get(start, end, mid + 1, right, 2 * v + 1));
    }

    void update(int pos, int value, int left = 1, int right = N - 1, int v = 1) {
        cost[v] = min(cost[v], value);

        if(left == right) return;

        int mid = (left + right) / 2;
        if(pos <= mid) update(pos, value, left, mid, 2 * v);
        else update(pos, value, mid + 1, right, 2 * v + 1);
    }
} minX, minY;

bool comp(Point p1, Point p2) { return p1.idx < p2.idx; }
bool comp1(Point p1, Point p2) { return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; }
bool comp2(Point p1, Point p2) { return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y; }

int main(){
    scanf("%d%d", &N, &Q);

    for(int i = 1; i <= N; i++) {
        scanf("%d%d", &P[i].x, &P[i].y);
        P[i].idx = i;
    }

    sort(P + 1, P + 1 + N, comp1);
    for(int i = 1; i <= N; i++) {
        P[i].x_index = i;

        if(i != N) minX.update(i, P[i + 1].x - P[i].x);
    }

    sort(P + 1, P + 1 + N, comp2);
    for(int i = 1; i <= N; i++) {
        P[i].y_index = i;

        if(i != N) minY.update(i, P[i + 1].y - P[i].y);
    }

    sort(P + 1, P + 1 + N, comp);

    for(; Q > 0; Q--) {
        int start, end, hp;
        scanf("%d%d%d", &start, &end, &hp);

        if(start == end) printf("YES\n");
        else {
            int minheight = P[end].x_index < P[start].x_index ? minX.get(P[end].x_index, P[start].x_index - 1) : minX.get(P[start].x_index, P[end].x_index - 1);
            int minwidth = P[end].y_index < P[start].y_index ? minY.get(P[end].y_index, P[start].y_index - 1) : minY.get(P[start].y_index, P[end].y_index - 1);

            if(hp >= min(minheight, minwidth)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
