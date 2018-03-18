#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct P{
    int x, y;
};

bool operator<(P a, P b){
    return a.x > b.x;
};

int main(){
    int n, d;
    vector<pair<int, int> > bus;

    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        if(l > r)
            swap(l, r);
        bus.push_back({r, l});
    }
    cin >> d;

    sort(bus.begin(), bus.end());
    priority_queue<P> pq;

    int ans = 0;

    for(int i = 0; i < n; i++){
        pq.push({bus[i].second, bus[i].first});
        while(!pq.empty() && bus[i].first - pq.top().x > d)
            pq.pop();

        ans = max(ans, (int)pq.size());
    }

    cout << ans << '\n';

    return 0;
}
