#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m;
bool isprime(int num) {
    if(num == 1) return false;
    for(int i = 2; i <= sqrt(num); i++) if(num % i == 0) return false;

    return true;
}

int main(){
    int ans[2] = {0, 1000000000};
    scanf("%d%d", &n, &m);
    for(int i = n; i <= m; i++) if(isprime(i)) {
        ans[0] += i;
        ans[1] = min(ans[1], i);
    }

    if(ans[0]) printf("%d\n%d\n", ans[0], ans[1]);
    else printf("-1\n");

    return 0;
}
