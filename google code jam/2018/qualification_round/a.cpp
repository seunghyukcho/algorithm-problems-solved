#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int t, d, beam, damage, ans;
string input;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        ans = 0, beam = 1, damage = 0;
        cin >> d >> input;

        for(auto ch : input){
            if(ch == 'C')
                beam <<= 1;
            else
                damage += beam;

        }

        for(int i = input.size() - 1; i >= 0; i--){
            char here = input[i];
            int hack = i + 1;

            if(here == 'C'){
                while(damage > d && hack < input.size() && input[hack] == 'S'){
                    hack++;
                    damage -= beam / 2;
                    ans++;
                }
                char sp = input[i];
                input[i] = input[hack - 1];
                input[hack - 1] = sp;
                beam >>= 1;
            }
        }

        printf("Case #%d: ", cs);
        if(damage > d)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
