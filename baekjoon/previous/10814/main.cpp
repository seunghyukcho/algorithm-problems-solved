#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool cmp(pair<int, string> s1, pair<int, string> s2){
    return s1.first < s2.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, string> > v;
    for(int i = 0; i < n; i++){
        string name;
        int age;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(auto i : v)cout << i.first << ' ' << i.second << '\n';

    return 0;

}
