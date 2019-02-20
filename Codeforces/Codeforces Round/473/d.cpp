#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int n, a, pr[2000002];
vector<vector<int> > dv(2000002);
set<int> s;
bool lex = false;

int main(){
    for(int i = 2; i <= 2e6; i++){
        if(!pr[i]){
            for(int j = i; j <= 2e6; j += i){
                pr[j] = 1;
                dv[j].push_back(i);
            }
        }
        s.insert(i);
    }

    for(cin >> n; n > 0; n--){
        cin >> a;
        int cur = *s.begin();

        if(!lex){
            cur = *s.lower_bound(a);
            if(cur != a)
                lex = true;
        }

        printf("%d ", cur);
        for(auto d : dv[cur]){
            for(int i = d; i <= 2e6; i += d){
                if(pr[i]){
                    s.erase(i);
                    pr[i] = 0;
                }
            }
        }
    }
    printf("\n");

    return 0;
}
