#include <iostream>
#include <string>

using namespace std;

int cnt[10];
string s;

int main()
{
	cin >> s;
	for(char ch : s)
		cnt[ch - '0']++;

	int mx = 0;
	for(int i = 0; i < 10; i++)
		if(i != 6 && i != 9)
			mx = max(cnt[i], mx);

	mx = max(mx, min(cnt[6], cnt[9]));
	cnt[6] = max(0, cnt[6] - mx);
	cnt[9] = max(0, cnt[9] - mx);

	cout << mx + (cnt[6] / 2 + cnt[6] % 2) + (cnt[9] / 2 + cnt[9] % 2) << '\n';
}