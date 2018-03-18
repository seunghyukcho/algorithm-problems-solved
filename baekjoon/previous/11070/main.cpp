#include<iostream>
#include<vector>

using namespace std;

struct B{
    int plus, minus;
};

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int n, m;
        cin >> n >> m;
        
        vector<B> team(1);
        for(int i = 0; i < n; i++){
            B b;
            b.plus = 0;
            b.minus = 0;
            team.push_back(b);
        }
        for(int i = 0; i < m; i++){
            int a, b, p, q;
            cin >> a >> b >> p >> q;

            team[a].plus += p;
            team[a].minus += q;
            team[b].plus += q;
            team[b].minus += p;
        }

        float min = 1e9, max = -1e9;
        for(int i = 1; i <= n; i++){
            float pythagoras;
            if(team[i].plus + team[i].minus != 0)
                pythagoras = (float)team[i].plus * team[i].plus / (team[i].plus * team[i].plus + team[i].minus * team[i].minus);
            else
                pythagoras = 0.0;
            
            if(min > pythagoras)
                min = pythagoras;
            if(max < pythagoras)
                max = pythagoras;
        }
        cout << (int)(1000*max) << '\n' << (int)(1000 * min) << '\n';
    }

    return 0;
}
