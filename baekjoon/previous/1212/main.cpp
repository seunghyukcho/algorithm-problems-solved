#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void convert(int num, int flag = 0){
    vector<int> v;
    while(num > 0){
        v.push_back(num % 2);
        num /= 2;
        flag++;
    }
    while(flag < 3){
        v.push_back(0);
        flag++;
    }

    reverse(v.begin(), v.end());
    for(auto i : v)cout << i;
}

int main(){
    string s;
    cin >> s;
    convert(*s.begin() - '0', 3);
    if(*s.begin() == '0')cout << 0;
    for(auto i = s.begin() + 1; i < s.end(); i++){
        int num = *i - '0';
        convert(num);
    }
    cout<< '\n';
    return 0;
}
