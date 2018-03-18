#include<iostream>
#include<vector>

using namespace std;

vector<int> transform(int n, int b);
bool check(vector<int> &s);

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int num, i;
        cin >> num;
        for(i = 2; i < 65; i++){
            vector<int> s;
            s = transform(num, i);
            if(check(s))
                break;
        }
        if(i == 65)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }

    return 0;
}

vector<int> transform(int n, int b){
    vector<int> ret;
    while(n > 0){
        ret.push_back(n % b);
        n /= b;
    }

    return ret;
}

bool check(vector<int> &s){
    bool ret = true;
    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - 1 - i]){
            ret = false;
            break;
        }
    }

    return ret;
}
