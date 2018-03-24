#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
char map[52][52];
bool vis[52][52];

struct P{
  int x, y;
};

bool bfs(int x, int y){
  vector<int> rows, cols;

  queue<P> q;
  P p;
  p.x = x;
  p.y = y;
  q.push(p);

  vis[x][y] = true;
  rows.push_back(x);
  cols.push_back(y);

  while(!q.empty()){
    int herex = q.front().x;
    int herey = q.front().y;
    q.pop();

    for(int i = 0; i < m; i++){
      if(map[herex][i] == '#' && !vis[herex][i]){
        vis[herex][i] = true;

        for(int k = 0; k < rows.size(); k++){
          int here = rows[k];
          if(map[here][i] != '#')
            return false;
        }
        cols.push_back(i);
        for(int j = 0; j < n; j++){
          if(map[j][i] == '#' && !vis[j][i]){
            vis[j][i] = true;
            p.x = j;
            p.y = i;
            q.push(p);
          }
        }
        p.x = herex;
        p.y = i;
        q.push(p);
      }
    }
    for(int i = 0; i < n; i++){
      if(map[i][herey] == '#' && !vis[i][herey]){
        vis[i][herey] = true;

        for(int k = 0; k < cols.size(); k++){
          int here = cols[k];
          if(map[i][here] != '#')
            return false;
        }
        rows.push_back(i);
        for(int j = 0; j < n; j++){
          if(map[i][j] == '#' && !vis[i][j]){
            vis[j][i] = true;
            p.x = i;
            p.y = j;
            q.push(p);
          }
        }
        p.x = i;
        p.y = herey;
        q.push(p);
      }
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(vis[i][j])
        map[i][j] = '.';
  return true;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> map[i][j];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      if(map[i][j] == '#')
        if(!bfs(i, j)){
          printf("No\n");
          return 0;
        }
    }

  printf("Yes\n");

  return 0;
}
