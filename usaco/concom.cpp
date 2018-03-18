/*
ID : choseun1
TASK : concom
LANG : C++11
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector<vector<pair<int, int> > > graph(102);
vector<pair<int, int> > ans;
vector<int> vis(102);
vector<bool> exist(102);

int main(){
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int s, d, val;
		cin >> s >> d >> val;
		graph[s].push_back({d, val});
		exist[s] = exist[d] = true;
	}
	
	for(int start = 1; start <= 100; start++)
		if(exist[start]){
			for(int i = 1; i <= 100; i++)
				vis[i] = 0;
			vis[start] = 100;
			queue<int> q;
			q.push(start);
			
			while(!q.empty()){
				int here = q.front();
				q.pop();
				
				for(auto p : graph[here]){
					int next = p.first;
					int dis = p.second;
					
					if(vis[next] > 50)
						continue;
					
					vis[next] += dis;
					if(vis[next] > 50){
						ans.push_back({start, next});
						q.push(next);
					}
				}
			}
		}
	
	sort(ans.begin(), ans.end());
	for(auto print : ans)
		cout << print.first << ' ' << print.second << '\n';
	
	return 0;
}
