#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> adj[512];

bool visited[512];

int ch;

vector<int> ans;

bool dfs(int u)
{
   if(ans.size() == ch)
   {
      bool check = true;
      int size = adj[u].size();
      for(int i = 0; i < size; i++)
      {
         int v = adj[u][i];
         if(visited[v])
         {
            check = false;
            break;
         }
      }
      return check;
   }
   
   int size = adj[u].size();
   for(int i = 0; i < size; i++)
   {
      int v = adj[u][i];
      if(visited[v]) return false;
      visited[v] = true;
      ans.push_back(v);
      if(dfs(v)) return true;
      visited[v] = false;
      ans.pop_back();
   }
   
   return false;
}

int main()
{
   int T;
   cin >> T;
   while(T--)
   {
      int N;
      cin >> N;
      
      ch = 1 + log2(N);
      for(int i = 0; i < N; i++)
      {
         visited[i] = false;
         adj[i].clear();
      }
      
      for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
      {
         char c;
         cin >> c;
         if(i < j)
         {
            if(c=='W') adj[i].push_back(j);
            else if(c=='L') adj[j].push_back(i);
         }
      }
      
      for(int i = 0; i < N; i++)
      {
         for(int j = 0; j < N; j++) visited[j] = false;
         ans.clear();
         visited[i] = true;
         ans.push_back(i);
         if(dfs(i)) break;
      }
      
      for(int i = 0; i < ch; i++)
      cout << ans[i]+1 << ' ';
      
      cout << endl;
   }
   return 0;
}