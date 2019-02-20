#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n;
vector<char> ans1, ans2;

int main(){
    scanf("%d", &n);

    int herex = 1, herey = 1;
    while(n - herex + n - herey > n - 1) {
        int nextx = herex + 1, nexty = herey;
        char result[100];
        printf("? %d %d %d %d\n", nextx, nexty, n, n);
        fflush(stdout);
        scanf("%s", result);
        if(!strcmp(result, "YES")) {
            herex += 1;
            ans1.push_back('D');
        }
        else {
            herey += 1;
            ans1.push_back('R');
        }
    }

    herex = n, herey = n;
    while(herex - 1 + herey - 1 > n - 1) {
        int nextx = herex, nexty = herey - 1;
        char result[100];
        printf("? %d %d %d %d\n", 1, 1, nextx, nexty);
        fflush(stdout);
        scanf("%s", result);
        if(!strcmp(result, "YES")) {
            herey -= 1;
            ans2.push_back('R');
        }
        else {
            herex -= 1;
            ans2.push_back('D');
        }
    }

    printf("! ");
    for(auto ch : ans1) printf("%c", ch);
    for(int i = ans2.size() - 1; i >= 0; i--) printf("%c", ans2[i]);
    printf("\n");
    fflush(stdout);

    return 0;
}
