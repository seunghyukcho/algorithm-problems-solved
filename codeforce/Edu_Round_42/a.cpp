#include<iostream>

using namespace std;

long long a[200002], sum;
int n;

int main(){
    int ans;
    long long sum2 = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(ans = 0; ans < n; ans++){
        sum2 += a[ans];
        if(sum2 * 2 >= sum)
            break;
    }

    cout << ans + 1 << '\n';

    return 0;
}
