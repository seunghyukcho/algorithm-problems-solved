#include<iostream>

using namespace std;

bool visited[730];
int sum(int n) {
    int ret = 0;
    for(; n > 0; n /= 10) ret += (n % 10) * (n % 10);

    return ret;
}

int main(){
    int n;
    for(cin >> n; n != 1; n = sum(n)){
        if(n <= 9 * 9 * 9) {
            if(visited[n]) break;
            visited[n] = true;
        }
    }

    cout << (n != 1 ? "UNHAPPY\n" : "HAPPY\n");

    return 0;
}
