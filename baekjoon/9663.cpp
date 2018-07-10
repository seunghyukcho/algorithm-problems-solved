#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long ans;
int N;
vector<int> queen;

void backtracking(int row) {
    if(row == N) ans++;
    else {
        for(int i = 0; i < N; i++) {
            bool check = true;
            for(int j = 0; j < row && check; j++) {
                if(queen[j] == i || abs(j - row) == abs(queen[j] - i)) check = false;
            }

            if(check) {
                queen.push_back(i);
                backtracking(row + 1);
                queen.pop_back();
            }
        }
    }
}

int main() {
    cin >> N;

    backtracking(0);

    cout << ans << '\n';

    return 0;
}
