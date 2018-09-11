#include<iostream>
#include<string>

using namespace std;

string ans = "", input;
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> input;

    if(n == k) cout << input << '\n';
    else {
        for(int i = 0; i < input.size(); i++) {
            if(n > k && ans.size() > 0 && input[i] == ')' && ans.back() == '(') {
                ans.pop_back();
                n -= 2;
            } else ans += input[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
