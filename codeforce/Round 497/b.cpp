#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, w, h;
    int here;

    cin >> n >> w >> h;
    here = max(w, h);

    for(int i = 1; i < n; i++) {
        cin >> w >> h;
        if(here >= max(w, h)) here = max(w, h);
        else if(here < min(w, h)) {
            cout << "NO\n";
            return 0;
        }
        else here = min(w, h);
    }

    cout << "YES\n";

    return 0;
}
