#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, u, v;
        cin >> n >> u >> v;

        int prevObstacle;
        bool isSame = true, isBlocked = true;
        cin >> prevObstacle;
        for(int i = 1; i < n; i++) {
            int obstacle;
            cin >> obstacle;
            if(prevObstacle != obstacle) isSame = false;
            if(abs(prevObstacle - obstacle) > 1) isBlocked = false;
            prevObstacle = obstacle;
        }

        if(!isBlocked) cout << 0 << '\n';
        else if(isSame) cout << min(u + v, 2 * v) << '\n';
        else cout << min(u, v) << '\n';
    }

    return 0;
}
