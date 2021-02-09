#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int start = 1, end = n;
    while(start < end) {
        int mid = (start + end) / 2;
        cout << '?' << ' ' << mid << '\n';
        cout << '?' << ' ' << mid + 1 << '\n';
        cout.flush();

        int res1, res2;
        cin >> res1 >> res2;
        if(res1 < res2) end = mid;
        else start = mid + 1;
    }

    cout << '!' << ' ' << start << '\n';
    cout.flush();
}
