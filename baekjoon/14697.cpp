#include <iostream>

using namespace std;

int sz[3], N;

bool available(int idx, int remain) {
    if(idx == 3) return remain == 0;
    else {
        bool ret = false;
        for(int i = 0; i * sz[idx] <= remain; i++) ret |= available(idx + 1, remain - i * sz[idx]);
        return ret;
    }
}

int main() {
    for(int i = 0; i < 3; i++) cin >> sz[i];
    cin >> N;

    cout << available(0, N) << '\n';
}
