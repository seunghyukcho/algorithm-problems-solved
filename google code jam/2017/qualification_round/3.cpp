#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>

using namespace std;

int t;
long long n, k;
map<long long, long long> m;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case #" << cs << ": ";
        
        m.clear();
        long long total = 0;

        cin >> n >> k;
        m[n] = 1;

        while(true){
            long long next = m.rbegin()->first;
            
            long long L = (next - 1) / 2 + ((next - 1) % 2);
            long long R = (next - 1) / 2;
            
            total += m[next];
            if(total >= k){
                printf("%lld %lld\n", L, R);
                break;
            }

            m[L] += m[next];
            m[R] += m[next];
            m.erase(next);
        }
    }

    return 0;
}
            
