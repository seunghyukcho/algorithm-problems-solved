#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s;
vector<int> cnt[30];

int main()
{
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 'a'].push_back(i);
	}

	int odd = 0, even = 0;
	for(int i = 0; i <= 'z' - 'a'; i++)
		cnt[i].size() % 2 ? odd++ : even++;

	if(odd > 1) printf("Impossible\n");
	else
	{
		int mid = -1;
		vector<int> left, right;
		for(int i = 0; i <= 'z' - 'a'; i++)
		{
			for(int j = 0; j < cnt[i].size() / 2; j++)
				left.push_back(cnt[i][j]);

			if(cnt[i].size() % 2) mid = cnt[i][cnt[i].size() / 2];

			
		}
	}

}