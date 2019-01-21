#include<iostream>
#include<map>

using namespace std;

map<int, int> mx, my;
int n, ans;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		mx[x]++;
		my[y]++;
	}

	for(auto coor : mx) {
		if(coor.second > 1)
			ans++;
	}

	for(auto coor : my) {
		if(coor.second > 1)
			ans++;
	}

	cout << ans << '\n';
}
