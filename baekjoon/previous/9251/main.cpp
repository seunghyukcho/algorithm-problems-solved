#include<iostream>
#include<vector>
#include<string>

using namespace std;

string s1, s2;

vector<vector<int> > D(1002, vector<int>(1002, -1));

int max(int a, int b){
    return a > b ? a : b;
}

int Dy(int a, int b){
    if(a < 0 || b < 0)return 0;
    if(D[a][b] != -1)return D[a][b];

    if(*(s1.begin() + a) == *(s2.begin() + b))return D[a][b] = Dy(a - 1, b - 1) + 1;
    else return D[a][b] = max(Dy(a - 1, b), Dy(a, b - 1));
}

int main(){
    cin >> s1 >> s2;
    int num1 = s1.size();
    int num2 = s2.size(); 

    cout << Dy(num1 - 1, num2 - 1) << '\n';

    return 0;
}
