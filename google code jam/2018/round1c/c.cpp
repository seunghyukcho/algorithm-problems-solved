#include<iostream>
#include<vector>

using namespace std;

int t, n;
long long w[100002];
long long D[100002][2];

long long min(long long a, long long b){ return a < b ? a : b; }

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        long long ans = 0;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> w[i];

        }

        for(int i = 0; i < n; i++){
            long long mn[2] = {0, 0};
            for(int j = 0; j < i; j++){
                if(D[j][1] <= w[i] * 6){
                    if(mn[0] < D[j][0]){
                        mn[0] = D[j][0];
                        mn[1] = D[j][1];
                    }
                    else if(mn[0] == D[j][0])
                        mn[1] = min(D[j][1], mn[1]);
                }

                D[j][0] = mn[0] + 1;
                D[j][1] = mn[1] + w[i];

                ans = max(ans, D[j][0]);
            }
        }
        cout << "Case #" << cs << ": " << ans << '\n';
    }

    return 0;
}
