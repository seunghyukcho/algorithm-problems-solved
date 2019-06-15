#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
string word;
map<char, vector<pair<int, string> > > m1;
map<int, vector<string> > m2;
int cnt;
vector<pair<string, string> > ans;

pair<char, int> compute(string s)
{
	int cnt = 0;
	char v;

	for(auto ch : s)
	{
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			v = ch;
			cnt++;
		}
	}

	return { v, cnt };
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> word;

		auto result = compute(word);
		m1[result.first].push_back({result.second, word});
		m2[result.second].push_back(word);
	}

	for(auto it : m1)
	{
		auto v = it.second;
		sort(v.begin(), v.end());

		for(int i = 0; i < v.size() - 1; i++)
		{
			if(v[i].first != v[i + 1].first)
				continue;
			
		}
	}

}