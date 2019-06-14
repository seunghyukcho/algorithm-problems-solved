#include <iostream>
#include <string>

using namespace std;

int T;

int main()
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		int cnt1 = 0, cnt2 = 0;
		string s;

		cin >> s;
		for(char ch : s)
		{
			if(ch == '.')
				cnt1++;
			else if(ch == 'B')
				cnt2++;
		}

		if(cnt1 == 0 || cnt2 < cnt1)
			cout << "N\n";
		else
			cout << "Y\n";
	}
}
