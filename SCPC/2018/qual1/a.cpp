#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int t, n, k;
int a[200003];

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        priority_queue<int> pq;

        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        pq.push(-a[0]);

        for(int i = 1; i < n; i++){
            int here = a[i];
            int comp = -pq.top();pq.pop();

            if(abs(here - comp) <= k)
                pq.push(-comp);
            pq.push(-here);
        }

        cout << "Case #" << cs << '\n';
        cout << pq.size() << '\n';
    }

    return 0;
}
