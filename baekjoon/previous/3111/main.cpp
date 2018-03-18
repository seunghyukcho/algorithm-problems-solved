#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s, t;
    vector<char> left, right;
    int l, r;

    cin >> t >> s;
    l = 0;
    r = s.size() - 1;

    while(l <= r){
        for(; l <= r; l++){
            left.push_back(s[l]);
            if(left.size() < t.size())
                continue;
            
            bool check = true;
            for(int i = 0; i < t.size(); i++){
                if(t[i] != left[left.size() - t.size() + i]){
                    check = false;
                    break;
                }
            }

            if(check){
                for(int i = 0; i < t.size(); i++)
                    left.pop_back();
                l++;
                break;
            }
        }

        for(; l <= r; r--){
            right.push_back(s[r]);
            if(right.size() < t.size())
                continue;

            bool check = true;
            for(int i = 0; i < t.size(); i++){
                if(t[t.size() - 1 - i] != right[right.size() - t.size() + i]){
                    check = false;
                    break;
                }
            }

            if(check){
                for(int i = 0; i < t.size(); i++)
                    right.pop_back();
                r--;
                break;
            }
        }
    }
    
    reverse(left.begin(), left.end());

    for(auto ch : left){
        right.push_back(ch);
        if(right.size() < t.size())
            continue;

        bool check = true;
        for(int i = 0; i < t.size(); i++){
            if(t[t.size() - 1 - i] != right[right.size() - t.size() + i]){
                check = false;
                break;
            }
        }

        if(check){
            for(int i = 0; i < t.size(); i++)
                right.pop_back();
        }
    }
    
    reverse(right.begin(), right.end());

    for(auto ch : right)
        cout << ch;
    cout << '\n';

    return 0;
}

