#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solve(vector<int> &a, vector<int> &b) {
    int ans = 0, nbox = 1, pivot = 0, match = 0;
    vector<int> consecutive(b.size());
    vector<bool> matched(a.size(), false);

    consecutive[b.size() - 1] = 1;
    for(int i = b.size() - 2; i >= 0; i--) {
        if(b[i] + 1 == b[i + 1])
            consecutive[i] = consecutive[i + 1] + 1;
        else
            consecutive[i] = 1;
    }

    for(int i = 0; i < a.size(); i++) {
        if(binary_search(b.begin(), b.end(), a[i])) {
            matched[i] = true;
            match++;
        }
    }

    ans = match;
    queue<int> q;
    while(pivot < b.size()) {

    }

    return ans;
}

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, m;
        cin >> n >> m;

        vector<int> ap, an, bp, bn;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if(num > 0) ap.push_back(num);
            else an.push_back(num);
        }

        for(int i = 0; i < m; i++) {
            int num;
            cin >> num;

            if(num > 0) bp.push_back(num);
            else bn.push_back(num);
        }
    }
}
