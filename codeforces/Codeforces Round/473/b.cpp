#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int n, k, m;
string str[100002];
int cost[100002];
int group_cost[100002];

int main(){
    long long ans = 0;

    cin >> n >> k >> m;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int i = 0; i < n; i++)
        cin >> cost[i];

    map<string, int> group;
    for(int i = 0; i < k; i++){
        int num;

        group_cost[i] = 1e9;
        for(cin >> num; num > 0; num--){
            int input;
            cin >> input;

            group[str[input - 1]] = i;
            group_cost[i] = min(group_cost[i], cost[input - 1]);
        }
    }

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;

        ans += group_cost[group[s]];
    }

    cout << ans << '\n';

    return 0;
}
