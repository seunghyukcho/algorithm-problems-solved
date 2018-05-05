#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int t, n, l;
string ans = "-";

bool bruteforce(int len, string new_ans, vector<string> &check, vector<set<char> > &ch){
    if(len == l){
        for(int i = 0; i < n; i++)
            if(check[i] == new_ans)
                return false;
        ans = new_ans;
        return true;
    }

    for(auto num : ch[len]){
        if(bruteforce(len + 1, new_ans + num, check, ch))
            return true;
    }
    return false;
}

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        vector<set<char> > count(15);
        ans = "-";

        cin >> n >> l;
        vector<string> vincent;

        for(int i = 0; i < n; i++){
            string input;
            cin >> input;

            for(int i = 0; i < input.size(); i++)
                count[i].insert(input[i]);
            vincent.push_back(input);
        }

        bruteforce(0, "", vincent, count);
        cout << "Case #" << cs << ": " << ans << '\n';
    }

    return 0;
}
