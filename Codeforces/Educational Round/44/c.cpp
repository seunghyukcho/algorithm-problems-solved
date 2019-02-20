#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n, k, l;
long long a[100002];
vector<long long> minimum;

int main(){
    cin >> n >> k >> l;
    for(int i = 0; i < n * k; i++)
        cin >> a[i];
    sort(a, a + n * k);

    int start = 0;
    int end = n * k - 1;

    while(a[end] - a[0] > l)
        end--;

    if(end - start + 1 < n)
        cout << 0 << '\n';
        else{
        while(start <= end){
            int cnt = 1;

            minimum.push_back(a[start++]);

            while(start <= end && cnt < k && end - start + 1 + minimum.size() > n){
                start++;
                cnt++;
            }
        }

        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += minimum[i];

        cout << ans << '\n';
    }
    return 0;
}
