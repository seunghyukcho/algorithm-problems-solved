#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    vector<vector<int> > graph(N + 1, vector<int>());
    vector<bool> check(N + 1, false);
    vector<int> ans(N + 1, 0);

    for(int i = 0; i < N - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int next : graph[here]){
            if(check[next])
                continue;
            ans[next] = here;
            check[next] = true;
            q.push(next);
        }
    }

    for(int i = 2; i <= N; i++)
        printf("%d\n", ans[i]);

    return 0;
}
