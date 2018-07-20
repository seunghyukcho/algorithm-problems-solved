#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int h1, a1, c1, here;
int h2, a2;
vector<int> ans;

int main(){
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;

    here = h1;

    while(h2 > 0) {
        if(h2 - a1 <= 0) {
            ans.push_back(1);
            break;
        }
        else if(here <= a2) {
            ans.push_back(0);
            here -= a2;
            while(here <= 0) here += c1;
        } else {
            ans.push_back(1);
            h2 -= a1;
            here -= a2;
        }
    }

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << (ans[i] == 1 ? "STRIKE\n" : "HEAL\n");

    return 0;
}
