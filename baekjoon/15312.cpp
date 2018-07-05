#include<iostream>
#include<string>
#include<vector>

using namespace std;

int w[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main(){
    string a, b;
    vector<int> ans;

    cin >> a >> b;

    for(int i = 0; i < a.size(); i++){
        ans.push_back(w[a[i] - 'A']);
        ans.push_back(w[b[i] - 'A']);
    }

    while(ans.size() > 2) {
        vector<int> ret;
        for(int i = 0; i < ans.size() - 1; i++){
            ret.push_back((ans[i] + ans[i + 1]) % 10);
        }
        ans = ret;
    }

    cout << ans[0] << ans[1] << '\n';

    return 0;
}
