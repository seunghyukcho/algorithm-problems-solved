#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<pair<int, int> > pSorted(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            pSorted[i] = {p[i], i};
        }

        sort(pSorted.begin(), pSorted.end(), comp);
        int pivot = n;
        for(auto e: pSorted) {
            if(e.second >= pivot) continue;
            for(int i = e.second; i < pivot; i++) cout << p[i] << ' ';
            pivot = e.second;
        }

        cout << '\n';
    }
}
