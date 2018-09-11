#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int check[1010];
int opentime[1010];
bool determine[1010];

int main(){
    int n, m;
    for(int t = 0; t < 2; t++) {
        for(int i = 0; i <= 1001; i++) {
            check[i] = opentime[i] = 0;
            determine[i] = false;
        }

        if(cin >> n) {
            cin >> m;
            for(int i = 1; i <= n; i++) {
                string input;
                cin >> input;

                if(input != "?") {
                    opentime[i] = stoi(input);
                    determine[i] = true;
                }
            }

            double sum = 0;
            for(int i = 0; i < m; i++) {
                int s, e, d;
                cin >> s >> e >> d;

                sum += d / (double)m;
                check[s]++;
                check[e]--;
            }

            for(int i = 1; i <= n; i++) {
                if(!determine[i]) {
                    if(check[i] > 0) opentime[i] = -1e7;
                    else if(check[i] < 0) opentime[i] = 1e7;
                }

                sum += ((long long)opentime[i] * check[i]) / (double)m;
            }

            double T = 0 < sum ? sum : 0;

            cout << T << '\n';
            for(int i = 1; i <= n; i++) cout << opentime[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
