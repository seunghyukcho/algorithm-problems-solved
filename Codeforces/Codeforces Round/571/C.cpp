#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;
	int cnt1 = 0, cnt2 = 0, ans = 0;

	for(auto ch : b)
		cnt2 += (ch == '1' ? 1 : 0);
	for(int i = 0; i < b.size(); i++)
		cnt1 += (a[i] == '1' ? 1 : 0);
	ans += (cnt1 + cnt2) % 2 == 1 ? 0 : 1;

	for(int i = 1; i + b.size() <= a.size(); i++)
	{
		if(a[i - 1] == '1')
			cnt1--;
		if(a[i + b.size() - 1] == '1')
			cnt1++;

		if((cnt1 + cnt2) % 2 == 0)
			ans++;
	}

	cout << ans << '\n';
}