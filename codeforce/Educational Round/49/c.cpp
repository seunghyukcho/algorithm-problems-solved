#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int t, n, stick;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> t; t > 0; t--) {
        vector<int> check(10002, 0), v;
        long double mn = 5e9;
        int left, right;

        v.clear();
        for(cin >> n; n > 0; n--) {
            cin >> stick;
            check[stick]++;

            if(check[stick] == 2) v.push_back(stick);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++) {
            if(check[v[i]] >= 4) {
                long double P = 4 * v[i], S = v[i] * v[i];
                long double result = P * P / S;

                if(mn > result) {
                    mn = result;
                    left = right = v[i];
                }
            } else if(i != v.size() - 1) {
                long double P = 2 * (v[i] + v[i + 1]), S = v[i] * v[i + 1];
                long double result = P * P / S;

                if(mn > result) {
                    mn = result;
                    left = v[i];
                    right = v[i + 1];
                }
            }
        }

        cout << left << ' ' << left << ' ' << right << ' ' << right << '\n';
    }

    return 0;
}
