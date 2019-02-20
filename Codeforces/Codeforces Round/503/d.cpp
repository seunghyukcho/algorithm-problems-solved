#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, n1, n2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);
    int start = 1, end = 1 + n / 2;
    printf("? 1\n");
    fflush(stdout);
    scanf("%d", &n1);
    printf("? %d\n", end);
    fflush(stdout);
    scanf("%d", &n2);

    if(n2 - n1 == abs(end - start)) {
        printf("! -1\n");
        fflush(stdout);
        return 0;
    } else if(n1 == n2) {
        printf("? 1\n");
        fflush(stdout);
        return 0;
    }

    while(1) {
        if(n1 == n2) {
            printf("! %d\n", start);
            fflush(stdout);
            break;
        }

        int mid = (start + end) / 2, n3;
        printf("? %d\n", mid);
        fflush(stdout);
        scanf("%d", &n3);

        if(n1 == n3 || n2 == n3) {
            printf("! %d\n", mid);
            fflush(stdout);
            break;
        }

        if(n3 - n1 != abs(mid - start)) {
            n2 = n3;
            end = mid;
        } else {
            n1 = n3;
            start = mid;
        }
    }

    return 0;
}
