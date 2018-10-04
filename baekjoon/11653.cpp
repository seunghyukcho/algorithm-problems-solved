#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
vector<int> prime;
int n;

void erathosthenes(int n) {
    vector<bool> visited(n + 1, false);

    for(int i = 2; i <= n; i++) {
        if(!visited[i]) {
            prime.push_back(i);
            visited[i] = true;

            for(int j = i; j <= n; j += i) visited[j] = true;
        }
    }
}

vector<PII> factorize(int num) {
    vector<PII> ret;
    for(int i = 0; i < prime.size() && prime[i] <= num; i++) {
        if(num % prime[i] == 0) {
            PII here = {prime[i], 0};

            while(num % prime[i] == 0) {
                here.second++;
                num /= prime[i];
            }

            ret.push_back(here);
        }
    }

    return ret;
}

int main(){
    cin >> n;
    erathosthenes(n + 1);

    for(auto ans : factorize(n)) {
        for(int i = 0; i < ans.second; i++) cout << ans.first << '\n';
    }
}
