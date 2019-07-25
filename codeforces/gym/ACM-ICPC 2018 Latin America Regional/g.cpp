#include<iostream>

using namespace std;

int n, state[100002][3], ans;

int gate(int idx, int result) {
    cout << idx << ' ' << result << '\n';
    if(idx == 0) return 1;

    if(state[idx][2] == -1) {
        if(result == 0) return gate(state[idx][0], 1) + gate(state[idx][1], 1);
        else {
            int sum = 0;
            sum += gate(state[idx][0], 0) + gate(state[idx][1], 0);
            sum += gate(state[idx][0], 0) + gate(state[idx][1], 1);
            sum += gate(state[idx][0], 1) + gate(state[idx][1], 0);

            return sum;
        }
    } else return state[idx][2] != result ? 0 : 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> state[i][0] >> state[i][1] >> state[i][2];
    for(int i = 1; i <= n; i++) {
        if(state[i][2] != -1) {
            int sum = 0;
            if(state[i][2] == 1) sum = gate(state[i][0], 1) + gate(state[i][1], 1);
            else {
                sum += gate(state[i][0], 0) + gate(state[i][1], 0);
                sum += gate(state[i][0], 0) + gate(state[i][1], 1);
                sum += gate(state[i][0], 1) + gate(state[i][1], 0);
            }

            ans += sum;
        }
        cout << '\n';
    }

    cout << ans << '\n';
}
