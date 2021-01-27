#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n;

int main(){
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n / 2; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int ans1 = 0;
    int ans2 = 0;

    for(int i = 0; i < n / 2; i++){
        ans1 += abs(v[i] - (2 * (i + 1) - 1));
        ans2 += abs(v[i] - 2 * (i + 1));

    }

    cout << min(ans1, ans2) << '\n';

    return 0;
}
