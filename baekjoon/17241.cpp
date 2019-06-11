#include <iostream>
#include <vector>

using namespace std;

int N, M, Q;
vector<int> graph[200002];
bool visited1[200002];
bool visited2[200002];

int search(int v)
{
	int ret = 0;

	if(visited2[v])
		return ret;
	if(!visited1[v])
		ret = 1;

	visited1[v] = visited2[v] = true;

	for(int next : graph[v])
	{
		if(!visited1[next])
		{
			visited1[next] = true;
			ret++;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> Q;
	for(int i = 0; i < M; i++)
	{
		int s, t;
		cin >> s >> t;
		graph[s].push_back(t);
		graph[t].push_back(s);
	}

	for(int i = 0; i < Q; i++)
	{
		int here;
		cin >> here;

		cout << search(here) << '\n';
	}
}