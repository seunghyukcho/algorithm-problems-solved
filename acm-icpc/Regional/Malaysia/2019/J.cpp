#include <iostream>
#include <string>
#include <vector>

using namespace std;

int graph[6][6];
bool visited[6];
vector<int> ans;

void dfs(int v)
{
	visited[v] = true;

	for(int i = 0; i < 5; i++)
	{
		if(!visited[i] && graph[v][i])
			dfs(i);
	}

	ans.push_back(v);
}

int main()
{
	string input;

	for(int i = 0; i < 5; i++)
	{
		cin >> input;

		if(input[1] == '>')
			graph[input[0] - 'A'][input[2] - 'A'] = 1;
		else
			graph[input[2] - 'A'][input[0] - 'A'] = 1;
	}

	for(int i = 0; i < 5; i++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}

	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 5; j++)
		{
			if(graph[ans[i]][ans[j]])
			{
				cout << "impossible\n";
				return 0;
			}
		}

	for(int i : ans)
		cout << (char)(i + 'A');
	cout << '\n';
}