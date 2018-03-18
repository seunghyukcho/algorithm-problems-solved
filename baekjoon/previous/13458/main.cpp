#include<iostream>

using namespace std;

int arr[1000002];

int main(){
    int n, b, c;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> b >> c;

    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long sum = (arr[i] - b) / c + 1;
        if(arr[i] - b <= 0)
            sum = 1;
        else if((arr[i] - b) % c)
            sum++;
        ans += sum;
    }

    cout << ans << '\n';

    return 0;
}
