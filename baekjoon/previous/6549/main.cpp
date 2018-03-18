#include<iostream>
#include<stack>

using namespace std;

long long max(long long a, long long b){
    return a > b ? a : b;
}

int main(){
    int n;

    while(1){
        long long ans = 0;

        cin >> n;
        if(n == 0)
            break;

        stack<pair<int, int> > s;

        for(int i = 0; i < n; i++){
            long long height;
            cin >> height;

            if(s.empty()){
                s.push({height, i});
                continue;
            }

            while(!s.empty() && s.top().first > height){
                int width = i;
                long long h = s.top().first;
                s.pop();
                
                if(!s.empty())
                    width = i - s.top().second - 1;

                ans = max(ans, width * h);
            }
            s.push({height, i});
        }

        while(!s.empty()){
            ans = max(ans, (n - s.top().second) * s.top().first);
            s.pop();
        }

        printf("%lld\n", ans);
    }

    return 0;

}
