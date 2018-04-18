#include<iostream>
#include<vector>

using namespace std;

int n, m, t, total, candy[100002];
vector<int> ans;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> candy[i];
    for(int i = 0; i < m; i++){
        cin >> t;
        if(t == 1){
            int num;
            cin >> num;
            if(!candy[num]){
                ans.push_back(num);
                candy[num] = 1;
                total--;
            }
            candy[num]--;
        }
        else
            total++;
    }

    for(;total > 0; total--){
        ans.push_back(1);
    }
    for(auto i : ans)
        cout << i << '\n';

    return 0;
}
