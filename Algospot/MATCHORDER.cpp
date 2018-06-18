#include<iostream>
#include<algorithm>

using namespace std;

int c, n, a[102], b[102];
bool check[102];

int main(){
    for(cin >> c; c > 0; c--){
        int ans = 0;

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            check[i] = false;
        }

        sort(a, a + n);
        sort(b, b + n);

        for(int i = 0; i < n; i++){
            int here = 0;
            for(int j = 0; j < n; j++){
                if(b[j] <= a[i] && !check[j]){
                    here = j;
                    break;
                }
                else if(!check[j])
                    here = j;
            }

            if(a[i] >= b[here])
                ans++;
            check[here] = true;
        }

        cout << ans << '\n';
    }

    return 0;
}
