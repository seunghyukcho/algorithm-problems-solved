#include <iostream>

using namespace std;

int N;

int main()
{
	int group, line, idx;
	cin >> N;

	group = (N - 1) / 14;
	N = (N - 1) % 14;

	line = N / 4;
	idx = (N % 4);

	if(idx == 0 && (line == 0 || line == 3))
		cout << "baby\n";
	else if(idx == 1 && (line == 0 || line == 3))
		cout << "sukhwan\n";
	else if(line == 1 && idx < 2)
		cout << (idx == 0 ? "very" : "cute") << '\n';
	else if(line == 2 && idx < 2)
		cout << (idx == 0 ? "in" : "bed") << '\n';
	else
	{
		int cnt = group + (idx + 1) % 2 + 1;
		cout << "tu";
		if(cnt < 5)
		{
			for(int i = 0; i < cnt; i++)
				cout << "ru";
			cout << '\n';
		}
		else
			cout << "+ru*" << cnt << '\n';
	}
}