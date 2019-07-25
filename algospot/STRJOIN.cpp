#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int c, n;

int main(){
    for(cin >> c; c > 0; c--){
        priority_queue<int> pq;
        int ans = 0;

        cin >> n;
        for(int i = 0; i < n; i++){
            int len;
            cin >> len;

            pq.push(-len);
        }

        while(1){
            int str1 = pq.top();pq.pop();
            if(pq.empty())
                break;
            int str2 = pq.top();pq.pop();

            ans += str1 + str2;
            pq.push(str1 + str2);
        }

        cout << -ans << '\n';
    }

    return 0;
}
