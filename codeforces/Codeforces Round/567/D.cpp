#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int n, m, q;
int cnt[500002];

map<int, vector<int> > mv;
vector<pair<int, int> > pv;

vector<int> sorted;

void merge(vector<int>& v1, vector<int>& v2)
{
	sorted.clear();
	sorted = vector<int>(v1.size() + v2.size());

	int idx = 0, left = 0, right = 0;

	while(left < v1.size() || right < v2.size())
	{
		if(left == v1.size() || (right < v2.size() && v1[left] > v2[right]))
			sorted[idx++] = v2[right++];
		else
			sorted[idx++] = v1[left++];
	}

	v1.clear();
	v1 = sorted;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> q;

	int num, mx = 0, mn = 1e9;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		cnt[num]++;
	}

	for(int i = 1; i <= m; i++)
	{
		mv[cnt[i]].push_back(i);
		mx = max(mx, cnt[i]);
		mn = min(mn, cnt[i]);
	}

	int prev1;
	vector<int> prev2;
	mv.erase(mx);

	for(auto& p : mv)
	{
		if(p.first != mn)
		{
			if(p.first != mx)
				merge(p.second, prev2);
			pv.push_back({(p.first - prev1) * prev2.size(), prev1});
		}

		prev2.clear();
		prev1 = p.first;
		prev2 = p.second;
	}

	pv.push_back({(mx - prev1) * prev2.size(), prev1});

	for(int i = 0; i + 1 < pv.size(); i++)
		pv[i + 1].first += pv[i].first;
	
	for(int i = 0; i < q; i++)
	{
		ll t;
		cin >> t;

		if(t > (ll)mx * m)
			cout << (t - (ll)mx * m - 1) % m + 1 << '\n';
		else
		{
			t -= n;

			int start = 0, end = pv.size() - 1;
			while(start < end)
			{
				int mid = (start + end) / 2;

				if(pv[mid].first < t)
					start = mid + 1;
				else
					end = mid;
			}

			if(start != 0)
				t -= pv[start - 1].first;
			t -= 1;


			vector<int>& find = mv[pv[start].second];
			cout << find[t % find.size()] << '\n';
		}
	}
}