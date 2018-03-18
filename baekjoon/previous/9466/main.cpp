#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(;t > 0; t--){
        int n;
        cin >> n;
        vector<int> stu(n + 1);
        vector<int> check(n + 1, 0);
        for(int i = 1; i <= n; i++)cin >> stu[i];
        for(int i = 1; i <= n; i++){
            if(check[i])continue;
            vector<bool> check2(n + 1, 0);
            vector<int> path;
            int here = i;
            while(!check2[here]){
                check2[here] = true;
                path.push_back(here);
                if(check[here]){
                    for(auto it = path.begin(); *it != here; it++)check[*it] = -1;
                    break;
                }
                here = stu[here];
            }
            if(!check[here]){
                auto it = path.begin();
                for(; *it != here; it++)check[*it] = -1;
                for(; it != path.end(); it++)check[*it] = 1;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(check[i] ==- 1)ans++;
        }

        cout << ans << '\n';

    }

    return 0;
}
