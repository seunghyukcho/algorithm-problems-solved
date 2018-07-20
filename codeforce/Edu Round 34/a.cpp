#include<iostream>

using namespace std;

int main(){
    int n, x;
    for(cin >> n; n > 0; n--) {
        cin >> x;

        bool check = true;
        for(int j = 0; check && 3 * j <= x; j++) {
            if((x - 3 * j) % 7 == 0) {
                printf("YES\n");
                check = false;
            }
        }
        if(check) printf("NO\n");
    }

    return 0;
}
