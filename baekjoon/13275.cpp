#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string input;
long long MOD = 1000000000;

int mod(long long n){
    if(n >= 0)return n % MOD;
    return ((-n / MOD + 1) * MOD + n) % MOD;
}

bool check(int s, int l){
    while(s < l){
        if(input[s] != input[l])
            return false;
        s++;
        l--;
    }

    return true;
}

bool palindrome_check(int n){
    vector<int> pre_hash_table, suf_hash_table;

    int pre_hash = 0, suf_hash = 0, power = 1;
    for(int i = 0; i + n <= input.size(); i++){
        if(i == 0){
            for(int j = n - 1; j >= 0; j--){
                suf_hash = mod(suf_hash + 1LL * input[j] * power);
                if(j > 0)
                    power = mod(power * 2LL);
            }
        }
        else{
            suf_hash = mod(2 * (suf_hash - 1LL * input[i - 1] * power) + input[n + i - 1]);
        }

        suf_hash_table.push_back(suf_hash);
    }

    power = 1;
    for(int i = input.size() - 1; i - n + 1 >= 0; i--){
        if(i == input.size() - 1){
            for(int j = n - 1; j >= 0; j--){
                pre_hash = mod(pre_hash + 1LL * input[i - j] * power);
                if(j > 0)
                    power = mod(power * 2LL);
            }
        }
        else{
            pre_hash = mod(2 * (pre_hash - 1LL * input[i + 1] * power) + input[i + 1 - n]);
        }

        pre_hash_table.push_back(pre_hash);
    }

    reverse(pre_hash_table.begin(), pre_hash_table.end());

    for(int i = 0; i < suf_hash_table.size(); i++){
        if(suf_hash_table[i] == pre_hash_table[i]){
            if(check(i, i + n - 1))
                return true;
        }
    }

    return false;
}

int main(){
    cin >> input;

    int s = 1;
    int l = input.size();

    while(s + 1 < l){
        int mid1 = (s + l) / 2;
        int mid2 = mid1 + 1;
        if(palindrome_check(mid2))
            s = mid2;
        else if(palindrome_check(mid1))
            s = mid1;
        else
            l = mid1 - 1;
    }

    if(palindrome_check(l))
        cout << l << '\n';
    else
        cout << s << '\n';

    return 0;
}
