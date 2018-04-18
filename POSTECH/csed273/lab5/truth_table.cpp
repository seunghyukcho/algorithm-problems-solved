#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>

using namespace std;

struct Node{
    string str;
    vector<int> pos;
};

int comp(string str1, string str2){
    for(int i = 0; i < 6; i++){
        if(str1[i] == str2[i] || str1[i] == '-' || str2[i] == '-')
            continue;
        bool check = true;
        for(int j = 0; j < 6 && check; j++){
            if(i == j)
                continue;
            if(str1[j] != str2[j])
                check = false;
        }
        if(check)
            return i;
    }
    return -1;
}

string merge(string str1, int pos){
    string ret = str1;
    ret[pos] = '-';
    return ret;
}

string binary_string(int n){
    string ret = "";

    for(; n > 0; n /= 2){
        if(n % 2)
            ret.push_back('1');
        else
            ret.push_back('0');
    }

    while(ret.size() < 6)
        ret.push_back('0');

    reverse(ret.begin(), ret.end());

    return ret;
}

vector<Node> quine(vector<int> v){
    vector<Node> ret;
    vector<Node> here, next;

    for(auto num : v)
        here.push_back({binary_string(num), {num}});

    while(!here.empty()){
        vector<bool> visit(here.size(), false);

        for(int i = 0; i < here.size(); i++){
            bool check = true;
            for(int j = i + 1; j < here.size(); j++){
                int f = comp(here[i].str, here[j].str);
                if(f != -1){
                    visit[i] = visit[j] = true;

                    bool check2 = true;
                    string input = merge(here[i].str, f);
                    for(int k = 0; k < next.size() && check2; k++)
                        if(input == next[k].str)
                            check2 = false;
                    if(check2){
                        vector<int> new_num = here[i].pos;
                        for(auto num : here[j].pos)
                            new_num.push_back(num);
                        next.push_back({input, new_num});
                    }
                }
            }
        }

        for(int i = 0; i < here.size(); i++)
            if(!visit[i])
                ret.push_back(here[i]);
        here = next;
        next.clear();
    }

    return ret;
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
    cout << "=====Minterm of Each Output====\n";
    for(int i = 0; i < 6; i++){
        printf("C%d: ", i);
        for(auto here : v[i])
            cout << here << ' ';
        cout << '\n';
    }
    cout << "\n\n\n";
    cout << "=====Result of Quine-Mccluskey====\n";
    for(int i = 0; i < 6; i++){
        cout << "--------------------------------------------------------------------\n";
        printf("\n#Result of C%d", i);
        cout << "\n\n";
        auto result = quine(v[i]);
        for(auto output : result){
            cout << output.str << ' ';
            for(auto output2 : output.pos)
                cout << output2 << ' ';
            cout << '\n';
        }

        cout << "\n\n";
        for(auto num : v[i])
            printf("%3d", num);
        cout << '\n';

        for(int j = 0; j < result.size(); j++){
            for(auto num : v[i]){
                bool check = true;
                for(int k = 0; k < result[j].pos.size(); k++){
                    if(result[j].pos[k] == num){
                        check = false;
                        break;
                    }
                }
                if(check)
                    printf("   ");
                else
                    printf(" x ");
            }
            cout << "\n";
        }
    }

    cout << "--------------------------------------------------------------------\n";

    return 0;
}
