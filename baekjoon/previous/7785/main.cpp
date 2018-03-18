#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(string s1, string s2){
    return s1 > s2;
}

int main(){
    map<string, bool> m;
    vector<string> ans;
    int n;

    for(cin >> n; n > 0; n--){
        string name, proc;
        cin >> name >> proc;

        if(proc == "enter")
            m[name] = true;
        else
            m[name] = false;
    }

    for(auto i : m){
        if(i.second)
            ans.push_back(i.first);
    }
    
    sort(ans.begin(), ans.end(), comp);
    
    for(auto i : ans)
        cout << i << '\n';    
    
    return 0;
}
