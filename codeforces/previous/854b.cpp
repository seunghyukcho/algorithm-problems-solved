#include<iostream>

using namespace std;

int main(){
    int n, k;
    int min, max;
    int next;
        
    cin >> n >> k;

    if(k == 0 || n == k)
        min = 0;
    else
        min = 1;

    max = 0;
    next = 1;
    while(next <= k){
        if(3 * next - 1 < n)
            max += 2;
        else if(3 * next - 1 == n)
            max += 1;
        else if(3 * next - 1 == n + 1)
            max += 0;
        else
            max--;
        next++;
    }

    cout << min << ' ' << max << '\n';

    return 0;
}
