#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int color[6];
char ch[6] = {'R', 'O', 'Y', 'G', 'B', 'V'};
int t, n;

int main(){
    cin >> t;

    for(int cs = 1; cs <= t; cs++){
        vector<pair<int, int> > print;

        cin >> n;
        for(int i = 0; i < 6; i++){
            cin >> color[i];
            if(i % 2 == 0)
                print.push_back({color[i], i});
        }

        sort(print.begin(), print.end());

        printf("Case #%d: ", cs);
        if(print[0].first + print[1].first < print[2].first)
            printf("IMPOSSIBLE\n");
        else{
            for(int i = 0; i < print[0].first + print[1].first - print[2].first; i++)
                printf("%c%c%c", ch[print[2].second], ch[print[1].second], ch[print[0].second]);
            for(int i = 0; i < print[2].first - print[0].first; i++)
                printf("%c%c", ch[print[2].second], ch[print[1].second]);
            for(int i = 0; i < print[2].first - print[1].first; i++)
                printf("%c%c", ch[print[2].second], ch[print[0].second]);
            printf("\n");
        }
    }

    return 0;
}
