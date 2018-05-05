#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct E{
    int point;
    long long cost;
};

int n, m;
vector<vector<E> > child(40002);

long long bfs(int start, int end){
    vector<bool> visit(n + 2, false);
    queue<pair<int, int> > q;
    q.push({start, 0});
    visit[start] = true;

    while(!q.empty()){
        auto here = q.front();
        q.pop();

        for(auto next : child[here.first]){
            if(!visit[next.point]){
                visit[next.point] = true;
                if(next.point == end)
                    return here.second + next.cost;
                else
                    q.push({next.point, here.second + next.cost});
            }
        }
    }

    return -1;
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int s, t;
        long long c;
        cin >> s >> t >> c;

        child[s].push_back({t, c});
        child[t].push_back({s, c});
    }

    for(cin >> m; m > 0; m--){
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t) << '\n';
    }

    return 0;
}
