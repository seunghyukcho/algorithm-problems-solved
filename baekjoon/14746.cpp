#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int n, m, c1, c2;
vector<int> p, q;

int bin_search(int here) {
    int s = 0, t = q.size() - 1;

    while(s + 1 < t) {
        int mid = (s + t) / 2;

        if(q[mid] == here) return mid;
        else if(q[mid] > here) t = mid;
        else s = mid;
    }

    if(abs(here - q[s]) < abs(here - q[t])) return s;
    else return t;
}

int main(){
    int ans[2];
    ans[0] = 1e9, ans[1] = 0;
    cin >> n >> m;
    cin >> c1 >> c2;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        p.push_back(num);
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        q.push_back(num);
    }

    sort(q.begin(), q.end());

    for(int i = 0; i < n; i++) {
        int here = p[i];
        int next = bin_search(here);

        if(ans[0] > abs(here - q[next])) {
            ans[0] = abs(here - q[next]);
            ans[1] = 0;
        }

        if(ans[0] == abs(here - q[next])) {
            ans[1]++;
            if((next - 1 >= 0 && abs(here - q[next - 1]) == ans[0])) ans[1]++;
            else if(next + 1 < m && abs(here - q[next + 1]) == ans[0]) ans[1]++;
        }
    }

    cout << ans[0] + abs(c1 - c2) << ' ' << ans[1] << '\n';

    return 0;
}
