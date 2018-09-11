#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2100000000
using namespace std;
vector<int> z[200005];
int init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = min(init(arr, tree, node * 2, start, (start + end) / 2),
			init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int MIN(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return MAX;
	if (left <= start && end <= right)
		return tree[node];

	return min(MIN(tree, node * 2, start, (start + end) / 2, left, right),
		MIN(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, q, maxnum = 0;
	cin >> n >> q;
	vector<int> arr(200005), tree(1000000);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxnum = maxnum < arr[i] ? arr[i] : maxnum;
		if (arr[i] == 0) {
			z[0].push_back(i);
			arr[i] = 123456789;
		}
	}
	if (maxnum != q) {
		if (!z[0].size()) {
			cout << "NO";
			return 0;
		}
		else {
			arr[z[0][0]] = q;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 123456789)
			arr[i] = arr[i - 1];
	}
	for (int i = 0; i < n; i++)
		z[arr[i]].push_back(i);

	init(arr, tree, 1, 0, n - 1);

	for (int i = 1; i <= q; i++) {
		if (z[i].size()) {
			int ll = z[i][0], rr = z[i][z[i].size() - 1];
			int zz = MIN(tree, 1, 0, n - 1, ll, rr);
			if (zz < i) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES" << '\n';
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
