#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n, s, t;
vector<vector<int> > graph(52);
vector<int> num(52);
vector<int> ans;
vector<bool> visit(102, false);
int capacity[102][102];
int flow[102][102];

bool is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

int get_flow(int u, int maxcapacity){
    if(u == t)
        return maxcapacity;

    for(int next : graph[u]){
        if(visit[next])
            continue;
        visit[next] = true;
        int c = capacity[u][next] - flow[u][next];
        int f = get_flow(next, min(c, maxcapacity));
        if(f > 0){
            flow[u][next] += f;
            return f;
        }

        c = flow[next][u];
        f = get_flow(next, min(c, maxcapacity));
        if(f > 0){
            flow[next][u] -= c;
            return f;
        }
        visit[next] = false;
    }

    return 0;
}

bool get_max_flow(int here){
    int f, total = 0;
    for(int i = 0; i <= 2 * n + 1; i++)
        for(int j = 0; j <= 2 * n + 1; j++)
            flow[i][j] = 0;
    do{
        for(int i = 0; i <= 2 * n + 1; i++)
            visit[i] = false;
        visit[1] = visit[here] = true;

        f = get_flow(s, 1e9);
        total += f;
    } while(f > 0);
    cout << total << '\n';
    return ((total == (n - 2) / 2) ? true : false);
}

int main(){
    cin >> n;
    s = 0;
    t = 2 * n + 1;

    for(int i = 1; i <= n; i++){
        cin >> num[i];
        capacity[s][i] = 1;
        graph[s].push_back(i);

        capacity[n + i][t] = 1;
        graph[n + i].push_back(t);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(is_prime(num[i] + num[j])){
                graph[i].push_back(n + j);
                capacity[i][n + j] = 1;
            }
        }
    }

    for(auto here : graph[1]){
        if(get_max_flow(here))
            ans.push_back(num[here - n]);
    }

    if(ans.size() == 0)
        cout << -1;
    else{
        for(auto output : ans)
            cout << output << ' ';
    }
    cout << '\n';

    return 0;
}
