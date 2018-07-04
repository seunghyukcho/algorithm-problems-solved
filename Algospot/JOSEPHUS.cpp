#include<iostream>
#include<list>

using namespace std;

void josephus(int n, int k){
    list<int> survivors;
    for(int i = 1; i <= n; i++) survivors.push_back(i);

    auto kill = survivors.begin();
    while(n > 2){
        kill = survivors.erase(kill);
        if(kill == survivors.end()) kill = survivors.begin();
        n--;

        for(int i = 0; i < k - 1; i++) {
            kill++;
            if(kill == survivors.end()) kill = survivors.begin();
        }
    }

    cout << survivors.front() << ' ' << survivors.back() << '\n';
}

int main(){
    int c, n, k;
    for(cin >> c; c > 0; c--){
        cin >> n >> k;

        josephus(n, k);
    }

    return 0;
}
