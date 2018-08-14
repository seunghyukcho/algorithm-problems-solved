#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct P {
    int x, y;
};

struct Vertex {
    int region, color;
    vector<int> edge;
};

struct Edge {
    int start, end, idx;
    bool check;
};

vector<Vertex> V(900000);
vector<Edge> E;

int n, map[300][300], dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}, vnum[300][300], ans[2], vertex_num;
bool visited[300][300], dfs_visited[90000];

bool inb(int x, int y) {
    return x < 1 || y < 1 || x > n || y > n ? false : true;
}

void dfs(int& here, int& idx1, int& idx2, int& ret) {
    //cout << here << ' ' << idx1 << ' ' << idx2 << ' ' << ret << '\n';

    for(auto e : V[here].edge) {
        auto& next_edge = E[e];
        if(next_edge.check) continue;

        auto next = V[next_edge.end];
        if(next.color == idx1 || next.color == idx2) {
            next_edge.check = true;
            E[next_edge.idx ^ 1].check = true;

            if(!dfs_visited[next_edge.end]) ret += V[next_edge.end].region;
            dfs_visited[next_edge.end] = true;
            dfs(next_edge.end, idx1, idx2, ret);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        cin >> map[i][j];
        vnum[i][j] = -1;
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        if(!visited[i][j]) {
            Vertex& v = V[vertex_num];
            v.region = 1, v.color = map[i][j];
            vector<bool> visited2(90000, false);

            queue<P> q;
            q.push({i, j});
            visited[i][j] = true;
            vnum[i][j] = vertex_num;

            while(!q.empty()) {
                auto here = q.front(); q.pop();

                for(int k = 0; k < 4; k++) {
                    int nextx = here.x + dir[k][0];
                    int nexty = here.y + dir[k][1];

                    if(inb(nextx, nexty)) {
                        if(!visited[nextx][nexty] && map[nextx][nexty] == v.color) {
                            v.region++;
                            visited[nextx][nexty] = true;
                            vnum[nextx][nexty] = vertex_num;

                            q.push({nextx, nexty});
                        } else if(map[nextx][nexty] != v.color && vnum[nextx][nexty] != -1 && !visited2[vnum[nextx][nexty]]) {
                            Edge e1, e2;
                            e1.start = e2.end = vertex_num;
                            e2.start = e1.end = vnum[nextx][nexty];
                            e1.check = e2.check = false;
                            e1.idx = E.size();
                            e2.idx = E.size() + 1;

                            E.push_back(e1); E.push_back(e2);
                            v.edge.push_back(e1.idx);
                            V[vnum[nextx][nexty]].edge.push_back(e2.idx);

                            visited2[vnum[nextx][nexty]] = true;
                        }
                    }
                }
            }

            ans[0] = max(ans[0], v.region);
            vertex_num++;
        }
    }

    cout << ans[0] << '\n';

    for(int i = 0; i < vertex_num; i++) {
        for(auto e : V[i].edge) {
            if(!E[e].check) {
                for(int i = 0; i < vertex_num; i++) dfs_visited[i] = false;

                int region = V[i].region;
                dfs_visited[i] = true;
                dfs(i, V[i].color, V[E[e].end].color, region);

                ans[1] = max(ans[1], region);
            }
        }
    }

    cout << ans[1] << '\n';

    return 0;
}
