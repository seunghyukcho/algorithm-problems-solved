#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int t, s;
long long d, a, b;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        long long ans[2] = {0, 0};
        int visit[102][102];
        vector<pair<int, int> > v;
        set<int> m, n;

        cin >> s;
        for(int i = 0; i < s; i++){
            cin >> d >> a >> b;
            m.insert(d + a);
            n.insert(d - b);
            v.push_back({d + a, d - b});

            for(int j = 0; j < s; j++)
                visit[i][j] = 0;
        }

        for(auto here_m : m){
            for(auto here_n : n){
                int start = 0;
                int end = 0;

                while(end < s){
                    if(visit[start][end] != 0){
                        if(visit[start][end] == 1)
                            end++;
                        continue;
                    }

                    bool check = true;
                    for(int i = start; i <= end; i++)
                        if(v[i].first != here_m && v[i].second != here_n){
                            check = false;
                            break;
                        }

                    if(check){
                        visit[start][end] = 1;
                        if(ans[0] < end - start + 1){
                            ans[0] = end - start + 1;
                            ans[1] = 1;
                        }
                        else if(ans[0] == end - start + 1)
                            ans[1]++;
                        end++;
                    }
                    else{
                        if(end == start)
                            end++;
                        start++;
                    }
                }
            }
        }

        cout << "Case #" << cs << ": " << ans[0] << ' ' << ans[1] << '\n';
    }

    return 0;
}
