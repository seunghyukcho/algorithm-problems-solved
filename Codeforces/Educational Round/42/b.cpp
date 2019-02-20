#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, a, b, ans;
char seat[200002];

int main(){
    int flag = 0;
    vector<int> empty_seats;

    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> seat[i];

        if(seat[i] == '*'){
            if(flag)
                empty_seats.push_back(flag);
            flag = 0;
        }
        else
            flag++;
    }
    if(flag)
        empty_seats.push_back(flag);
    sort(empty_seats.begin(), empty_seats.end());

    for(auto here : empty_seats){
        if(a > b){
            int c = a;
            a = b;
            b = c;
        }
        if(here / 2 <= a){
            if(a + b < here){
                ans += a + b;
                a = b = 0;
            }
            else if(here % 2){
                ans += here;
                a -= here / 2;
                b -= here / 2 + 1;
            }
            else{
                ans += here;
                a -= here / 2;
                b -= here / 2;
            }
        }
        else{
            int next = here - 2 * a;
            b -= a;
            ans += 2 * a + min(b, next / 2 + next % 2);
            a = 0;
            b -= min(b, next / 2 + next % 2);
        }
    }

    cout << ans << '\n';

    return 0;
}
