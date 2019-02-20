#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<string, string> parent;
vector<string> ans;

string find(string s) {
    if(parent[s] == s) return s;
    return parent[s] = find(parent[s]);
}

void merge(string s1, string s2) {
    if(find(s1).size() <= find(s2).size()) parent[parent[s2]] = parent[s1];
    else parent[parent[s1]] = parent[s2];
}

bool isnumber(string s) {
    return s[0] == '-' || (s[0] >= '0' && s[0] <= '9') ? true : false;
}

int main(){
    ios::sync_with_stdio(false);

    string input1, input2;
    cin >> input1;

    stringstream input(input1);
    while(getline(input, input2, '&')) {
        ans.push_back(input2);
        getline(input, input2, '&');
    }

    for(auto here : ans) {
        stringstream ss(here);

        if(here.find("==") != string::npos) {
            string s1, s2;
            getline(ss, s1, '=');
            getline(ss, s2, '=');
            getline(ss, s2, '\n');

            if(parent.find(s1) == parent.end()) parent[s1] = s1;
            if(parent.find(s2) == parent.end()) parent[s2] = s2;

            if(find(s1) != find(s2)) merge(s1, s2);
        } else {
            string s1, s2;
            getline(ss, s1, '!');
            getline(ss, s2, '=');
            getline(ss, s2, '\n');

            if(parent.find(s1) == parent.end()) parent[s1] = s1;
            if(parent.find(s2) == parent.end()) parent[s2] = s2;
        }
    }

    vector<string> ans2;

    for(int i = 0; i < ans.size(); i++) {
        string here = ans[i];

        stringstream ss(here);
        string s1, s2;

        if(here.find("!=") != string::npos) {
            getline(ss, s1, '!');
            getline(ss, s2, '=');
            getline(ss, s2, '\n');

            ans2.push_back(find(s1) + "!=" + find(s2));
        }
    }

    map<string, string> numbercheck;

    for(auto& here : parent) {
        here.second = find(here.first);

        if(here.first != here.second) ans2.push_back(here.first + "==" + here.second);
    }

    for(int i = 0; i < ans2.size(); i++) {
        if(i) cout << "&&";
        cout << ans2[i];
    }

    if(ans2.size() == 0) {
        cout << "true\n";

        return 0;
    }

    cout << '\n';

    return 0;
}
