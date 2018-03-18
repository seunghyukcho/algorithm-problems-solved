#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Person{
    string name;
    int kor, eng, math;
};

bool cmp(Person s1, Person s2){
    return make_tuple(-s1.kor, s1.eng, -s1.math, s1.name) < make_tuple(-s2.kor, s2.eng, -s2.math, s2.name);
}

int main(){
    int n;
    cin >> n;
    vector<Person> v;
    for(int i = 0; i < n; i++){
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        v.push_back({name, kor, eng, math});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v)cout << i.name << '\n';
    
    return 0;
}
