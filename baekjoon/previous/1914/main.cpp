#include<iostream>

using namespace std;

long long D[102];

void hanoi1(int n, int pos1, int pos2){
    if(n == 1){
        printf("%d %d\n", pos1+1, pos2+1);
    }
    else{
        int pos3 = 0;
        while(pos3 == pos1 || pos3 == pos2)pos3++;
        hanoi1(n-1, pos1, pos3);
        printf("%d %d\n", pos1+1, pos2+1);
        hanoi1(n-1, pos3, pos2);
    }
}

long long hanoi2(int n){
    if(D[n])return D[n];
    return D[n] = hanoi2(n-1) * 2 + 1;
}

int main(){
    int n;
    cin >> n;
    D[1] = 1;
    long long ans = hanoi2(n);
    cout << ans << '\n';
    hanoi1(n, 0, 2);

    return 0;
}
