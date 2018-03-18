#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool cmp(string s1, string s2){
    return (s1.size() < s2.size()) || (s1.size() == s2.size() && s1 < s2);
}

int main(){
    int n;
    cin >> n;
    vector<string> word;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        word.push_back(s);
    }

    sort(word.begin(), word.end(), cmp);
    auto last = unique(word.begin(), word.end());
    word.erase(last, word.end());
    for(auto i : word)cout << i << '\n';

    return 0;
}


