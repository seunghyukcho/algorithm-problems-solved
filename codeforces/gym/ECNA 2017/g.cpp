#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n, flim;
vector<int> arr;
map<pair<int, int>, int> ma;
int cal(int day, int lim) {
	if (day == n - 1) {
		return min(lim, arr[day]);
	}
	if (day>n - 1)
		return 0;
	if (ma[make_pair(day, lim)] != 0)
		return ma[make_pair(day, lim)];
	return ma[make_pair(day, lim)] = max(min(lim, arr[day]) + cal(day + 1, lim * 2 / 3), max(min(lim, arr[day]) + cal(day + 2, lim),min(lim, arr[day]) + cal(day + 3, flim)));
}
int main() {
	scanf("%d%d", &n, &flim);
	for (int i = 0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	int m1 = cal(0, flim);
	int m2 = cal(1, flim);
	int m3 = cal(2, flim);
	printf("%d\n", max(m1,max(m2,m3)));
}
