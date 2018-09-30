#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXSIZE 400
#define MAX 1000000000

using namespace std;

struct FlowGraph {
    int capacity[MAXSIZE][MAXSIZE];
    int source, sink, level[MAXSIZE], start[MAXSIZE];
    vector<int> V[MAXSIZE];

    void setEdge(int u, int v, int c) {
        if(capacity[u][v] == 0) {
            capacity[u][v] = c;
            V[u].push_back(v);
            V[v].push_back(u);
        }
        else capacity[u][v] += c;
    }

    void levelGraph() {
        queue<int> q;
        for(int i = 0; i < MAXSIZE; i++) level[i] = -1;

        level[source] = 0;
        q.push(source);

        while(!q.empty()) {
            int here = q.front(); q.pop();

            for(int next : V[here]) {
                if(level[next] == -1 && capacity[here][next]) {
                    level[next] = level[here] + 1;
                    q.push(next);
                }
            }
        }
    }

    long long dfs(int u, int minFlow = MAX) {
        if(u == sink) return minFlow;

        for(; start[u] < V[u].size(); start[u]++) {
            int next = V[u][start[u]];

            if(level[next] == level[u] + 1 && capacity[u][next]) {
                long long f = dfs(next, min(minFlow, capacity[u][next]));

                if(f) {
                    capacity[u][next] -= f;
                    capacity[next][u] += f;
                    return f;
                }
            }
        }

        return 0;
    }

    long long maxflow() {
        long long ret = 0;
        while(1) {
            levelGraph();
            if(level[sink] == -1) break;

            for(int i = 0; i < MAXSIZE; i++) start[i] = 0;

            while(1) {
                long long flow = dfs(source);
                if(flow == 0) break;
                ret += flow;
            }
        }

        return ret;
    }
} G;

// 먼저 벡터를 표현하는 구조체를 정의합니다.
struct vector2{
    double x, y;

    vector2() {

    }

    vector2(double _x, double _y){
        x = _x, y = _y;
    }

    double cross(const vector2& other) const{
        return x*other.y-y*other.x;
    }

    vector2 operator * (double r) const{
        return vector2(x*r, y*r);
    }

    vector2 operator + (vector2 other) const{
        return vector2(x + other.x, y + other.y);
    }
    vector2 operator - (vector2 other) const{
        return vector2(x - other.x, y - other.y);
    }

    bool operator == (vector2 other) const{
        return x == other.x && y == other.y;
    }
    bool operator < (vector2 other) const{
        return x < other.x && y < other.y;
    }
};

double ccw(vector2 a, vector2 b){
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a-p, b-p);
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

int n, k, h, m;
vector2 mm[300], hh[52], w[1002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> h >> m;
    for(int i = 1; i <= n; i++) cin >> w[i].x >> w[i].y;
    w[0].x = w[n].x, w[0].y = w[n].y;
    for(int i = 0; i < h; i++) cin >> hh[i].x >> hh[i].y;
    for(int i = 0; i < m; i++) cin >> mm[i].x >> mm[i].y;

    G.source = 0;
    G.sink = h + m + 1;

    for(int i = 0; i < m; i++) {
        G.setEdge(0, i + 1, 1);

        for(int j = 0; j < h; j++) {
            bool flag = true;

            for(int k = 0; k < n && flag; k++) {
                if(w[k].x == w[k + 1].x) {
                    if(hh[j].x == w[k].x) continue;
                }
                if(w[k].y == w[k + 1].y) {
                    if(hh[j].y == w[k].y) continue;
                }

                flag = !segmentIntersects(mm[i], hh[j], w[k], w[k + 1]);
            }

            // cout << i << ' ' << j << ' ' << (flag ? "1" : "2") << '\n';
            if(flag) G.setEdge(1 + i, m + 1 + j, 1);
        }
    }

    for(int i = 0; i < h; i++)
        G.setEdge(1 + m + i, h + m + 1, k);

    bool ans = (m - G.maxflow() == 0 ? true : false);
    cout << (ans ? "Possible\n" : "Impossible\n");

    return 0;
}
