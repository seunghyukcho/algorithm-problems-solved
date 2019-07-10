#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int n;
string t;

int convertTime(int& pos)
{
	int ret = t[pos++] - '0';
	if(t[pos] != ':')
		ret = ret * 10 + t[pos++] - '0';
	pos++;

	return ret;
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n == 0)
			break;

		int ans = 0;
		for(; n > 0; n--)
		{
			cin >> t;
			char type = t[0];
			int h1, h2, m1, m2, s1, s2;

			int pos = 2;
			h1 = convertTime(pos);
			m1 = convertTime(pos);
			s1 = convertTime(pos);
			h2 = convertTime(pos);
			m2 = convertTime(pos);
			s2 = convertTime(pos);

			int start = h1 * 3600 + m1 * 60 + s1, end = h2 * 3600 + m2 * 60 + s2;
			if(type == 'D')
			{
				start = max(start, 8 * 3600 + 30 * 60);
				if(start > 9 * 3600 + 30 * 60)
				{
					ans++;
					continue;
				}
				
				if(end - start < 8 * 3600)
					ans++;
			}
			else
			{
				start = max(start, 8 * 3600 + 30 * 60);
				if(start > 12 * 3600 + 30 * 60)
				{
					ans++;
					continue;
				}
				
				if(end - start < 9 * 3600)
					ans++;
			}
		}

		if(ans == 0)
			cout << "All OK\n";
		else if(ans <= 3)
			cout << ans << ' ' << "Point(s) Deducted\n";
		else
			cout << "Issue Show Cause Letter\n";
	}
}