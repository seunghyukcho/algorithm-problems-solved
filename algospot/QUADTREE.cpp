#include<iostream>

using namespace std;

string s;

int dq(int n) {
	if(s[n] != 'x')
		return 1;
	else {
		int ret = n + 1;

		for(int i = 0; i < 4; i++)
			ret = ret + dq(ret);

		return ret - n;
	}
}

void change(int st) {
	if(s[st] != 'x') {
		cout << s[st];
		return;
	}

	int ul = st + 1;
	int ur = ul + dq(ul);
	int dl = ur + dq(ur);
	int dr = dl + dq(dl);

	cout << 'x';
	change(dl);
	change(dr);
	change(ul);
	change(ur);
}
	

int main() {
	int c;
	for(cin >> c; c > 0; c--) {
		cin >> s;

		if(s[0] != 'x') cout << s << '\n';
		else {
			change(0);	
			cout << '\n';
		}
	}

	return 0;
}
