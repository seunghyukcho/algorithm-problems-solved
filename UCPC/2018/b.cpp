#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
long long ans = 0;

int main(){
    priority_queue<long long> pq;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        pq.push(-num);
    }

    for(int i = 0; i < m; i++) {
        long long c1 = pq.top(); pq.pop();
        long long c2 = pq.top(); pq.pop();

        long long sum = c1 + c2;
        pq.push(sum); pq.push(sum);
    }

    while(!pq.empty()) {
        ans += -pq.top(); pq.pop();
    }

    cout << ans << '\n';

    return 0;
}
