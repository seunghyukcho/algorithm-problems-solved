#include<iostream>
#include<vector>

using namespace std;

int n, m;
long long board[502][502], sum, determine;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> board[i][j];

    long long sum3 = 0, sum4 = 0;
    bool check3 = true, check4 = true;
    for(int i = 1; i <= n; i++) {
        long long sum1 = 0, sum2 = 0;
        bool check1 = true, check2 = true;
        for(int j = 1; j <= n; j++) {
            sum1 += board[i][j];
            sum2 += board[j][i];

            if(board[i][j] == 0) check1 = false;
            if(board[j][i] == 0) check2 = false;
        }

        sum3 += board[i][i];
        sum4 += board[n - i + 1][i];

        if(board[i][i] == 0) check3 = false;
        if(board[n - i + 1][i] == 0) check4 = false;

        if(check1) {
            if(sum == 0) sum = sum1;
            else if(sum != sum1) {
                m = -1;
                break;
            }
        } else {
            if(determine == 0) determine = sum1;
            else if(determine != sum1) {
                m = -1;
                break;
            }
        }

        if(check2) {
            if(sum == 0) sum = sum2;
            else if(sum != sum2) {
                m = -1;
                break;
            }
        } else {
            if(determine == 0) determine = sum2;
            else if(determine != sum2) {
                m = -1;
                break;
            }
        }
    }

    if(check3) {
        if(sum == 0) sum = sum3;
        else if(sum != sum3) {
            m = -1;
        }
    } else {
        if(determine == 0) determine = sum3;
        else if(determine != sum3) {
            m = -1;
        }
    }

    if(check4) {
        if(sum == 0) sum = sum4;
        else if(sum != sum4) {
            m = -1;
        }
    } else {
        if(determine == 0) determine = sum4;
        else if(determine != sum4) {
            m = -1;
        }
    }

    cout << (m == -1 ? m : sum - determine) << '\n';

    return 0;
}
