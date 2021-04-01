#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int A[100002], N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    cin >> M;

    sort(A, A + N);
    for(int i = 0; i < M; i++) {
        int q;
        cin >> q;

        int s = 0, e = N - 1;
        while(s <= e) {
            int mid = (s + e) / 2;
            if(A[mid] == q) {
                cout << 1 << '\n';
                break;
            }
            else if(A[mid] < q) s = mid + 1;
            else e = mid - 1;
        }

        if(e < s) cout << 0 << '\n';
    }
}
