#include<iostream>

using namespace std;

bool used[10];
int ans = -1, n;

bool check(int num) {
    if(num <= 0) return false;
    bool visit[10];
    for(int i = 0; i <= 9; i++) visit[i] = used[i];
    for(; num > 0; num /= 10) {
        if(visit[num % 10]) return false;
        visit[num % 10] = true;
    }

    return true;
}

void make_num(int len, int num) {
    if(len == 0) {
        if(check(n - num)) ans = num;
        return;
    }

    if(num == 0) {
        for(int i = 1; i <= 9; i++) {
            used[i] = true;
            make_num(len - 1, i);
            used[i] = false;
        }
    } else {
        for(int i = 0; i <= 9; i++) {
            if(!used[i]) {
                used[i] = true;
                make_num(len - 1, num * 10 + i);
                used[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= 9 && ans == -1; i++) {
        make_num(i, 0);
    }

    if(ans == -1) cout << ans << '\n';
    else cout << ans << " + " << n - ans << '\n';

    return 0;
}
