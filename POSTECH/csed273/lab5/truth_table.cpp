#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>

using namespace std;

int comp(string str1, string str2){
    for(int i = 0; i < 6; i++){
        if(str1[i] == str2[i] || str1[i] == '-' || str2[i] == '-')
            continue;
            
    }
}

vector<string> quine(vector<int> v){

}

int main(){
    vector<vector<int> > v(6);

    for(int a = 0; a < 8; a++){
        for(int b = 0; b < 8; b++){
            int mul = a * b;
            int k = 0;
            for(int i = mul; i > 0; i /= 2){
                if(i % 2)
                    v[k].push_back((a << 3) + b);
                k++;
            }
        }
    }

    for(int i = 0; i < 6; i++){
        for(auto here : v[i])
            cout << here << ' ';
        cout << '\n';
    }

    return 0;
}
