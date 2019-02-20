#include<iostream>
#include<algorithm>

using namespace std;

bool used[5002];

int main() {
    int n, a[5002];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int total = n;
    sort(a, a + n);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(!used[j] && a[i] < a[j]) {
                used[j] = true;
                total--;
                break;
            }
        }
    }

    cout << total << '\n';

    return 0;
}
