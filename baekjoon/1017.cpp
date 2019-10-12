#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
vector<bool> visit(102, false);
int capacity[55][55];
int flow[55][55];

bool is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;

    return true;
}

int get_flow(int u, int maxcapacity){
    if(u == n + 1)
        return maxcapacity;

    for(int i = 0; i <= n + 1; i++){
        if(visit[i])
            continue;

        int f = 0;
        int c = capacity[u][i] - flow[u][i];

        if(c > 0){
            visit[i] = true;
            f = get_flow(i, min(maxcapacity, c));
            if(f > 0){
                flow[u][i] += maxcapacity;
                return f;
            }
        }

        f = 0;
        c = flow[i][u];

        if(c > 0){
            visit[i] = true;
            f = get_flow(i, min(maxcapacity, c));
            if(f > 0){
                flow[i][u] -= maxcapacity;
                return f;
            }
        }
    }

    return 0;
}

int get_max_flow(int check){
    int f = 0, ret = 0;

    do{
        for(int i = 0; i <= n + 1; i++)
            visit[i] = false;

        visit[0] = visit[1] = visit[check] = true;

        f = get_flow(0, 1e9);
        ret += f;
    } while(f > 0);

    return ret;
}

int main(){
    vector<int> left, right, ans;
    bool check = false;
    int num;

    cin >> n;

    cin >> num;
    if(num % 2)
        check = true;
    left.push_back(num);

    for(int i = 1; i < n; i++){
        int num;
        cin >> num;

        if((num % 2 && check) || (num % 2 == 0 && !check))
            left.push_back(num);
        else
            right.push_back(num);
    }

    if(left.size() == right.size()){
        int sz = left.size();
        for(int i = 0; i < sz; i++){
            capacity[0][i + 1] = 1;
            for(int j = 0; j < right.size(); j++){
                capacity[sz + j + 1][n + 1] = 1;
                if(is_prime(left[i] + right[j]))
                    capacity[i + 1][sz + j + 1] = 1;
            }
        }


        for(int i = 0; i < right.size(); i++){
            if(capacity[1][sz + 1 + i] == 0)
                continue;

            for(int j = 0; j <= n + 1; j++)
                for(int k = 0; k <= n + 1; k++)
                    flow[j][k] = 0;
            int result = get_max_flow(sz + 1 + i);
            if(result == right.size() - 1)
                ans.push_back(right[i]);
        }
    }

    if(ans.size() == 0)
        cout << -1 << '\n';
    else{
        sort(ans.begin(), ans.end());
        for(auto output : ans)
            cout << output << ' ';
        cout << '\n';
    }

    return 0;
}