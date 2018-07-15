#include<iostream>

using namespace std;

int main(){
    int limit = 0, n, m;

    cin >> n >> m;

    limit = n - 1;
    for(int i = 2; i < n; i++) {
        limit += n - i - n / i + 1;
    }

    if(limit < m) cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for(int i = 2; i <= n && m; i++, m--) cout << 1 << ' ' << i << '\n';
        for(int i = 2; i <= n && m; i++) {
            for(int j = 1; j * i <= n && m; j++) {
                for(int k = 1; k < i; k++, m--) cout << i << ' ' << i
            }
        }
    }
}
