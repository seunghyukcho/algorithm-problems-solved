#include<iostream>
#include<vector>

using namespace std;

bool check[10000000];
vector<int> prime;
int k;

int main(){
    cin >> k;
    for(int i = 2; i < 10000000; i++) {
        if(!check[i]) {
            prime.push_back(i);
            for(int j = i; j < 10000000; j += i) check[j] = true;
        }
    }

    cout << prime[k - 1] << '\n';

    return 0;
}
