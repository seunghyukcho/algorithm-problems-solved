#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
int t, n;

int main()
{
	for(cin >> t; t > 0; t--)
	{
		m.clear();
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;

			m[s2]++;
		}

		int ans = 1;
		for(auto clothes : m)
			ans *= clothes.second + 1;

		cout << ans - 1 << '\n';
	}
}