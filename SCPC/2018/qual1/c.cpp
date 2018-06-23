#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int t, n, m;

bool binary_check(vector<int> &v, int find){
    int start = 0, end = v.size() - 1;

    while(start < end){
        int mid = (start + end) / 2;
        if(v[mid] == find)
            return true;
        else if(v[mid] > find)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return (v[start] == find);
}

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> n >> m;

        vector<int> degree(n + 1);
        vector<vector<int> > graph(n + 1);
        vector<bool> visited(n + 1, false);
        queue<int> q;
        int ans = n;

        for(int i = 0; i < m; i++){
            int s, e;
            cin >> s >> e;

            degree[s]++;
            degree[e]++;

            graph[s].push_back(e);
            graph[e].push_back(s);
        }

        for(int i = 1; i <= n; i++){
            sort(graph[i].begin(), graph[i].end());

            if(degree[i] == 2)
                q.push(i);
        }

        while(!q.empty()){
            int here = q.front();
            q.pop();

            if(degree[here] != 2)
                continue;

            int next[2] = {0, 0};
            for(auto conn : graph[here]){
                if(!visited[conn]){
                    if(next[0] == 0)
                        next[0] = conn;
                    else{
                        next[1] = conn;
                        break;
                    }
                }
            }

            if(binary_check(graph[next[0]], next[1])){
                visited[here] = true;
                ans--;

                degree[next[0]]--;
                if(degree[next[0]] == 2)
                    q.push(next[0]);

                degree[next[1]]--;
                if(degree[next[1]] == 2)
                    q.push(next[1]);
            }
        }

        cout << "Case #" << cs << '\n';
        cout << ans << '\n';
    }

    return 0;
}
