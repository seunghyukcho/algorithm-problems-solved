#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int color[6];
char ch[6] = {'R', 'O', 'Y', 'G', 'B', 'V'};
int t, n;

int main(){
    cin >> t;

    for(int cs = 1; cs <= t; cs++){
        bool ans1 = true;
        bool circle = false;
        int idx = -1;
        vector<int> ans2;

        cin >> n;
        for(int i = 0; i < 6; i++)
            cin >> color[i];

        for(int i = 0; i < 3; i++){
            int here = 2 * i + 1;
            if(!color[here])
                continue;
            if(color[here] == color[(here + 3) % 6]){
                if(circle){
                    ans1 = false;
                    break;
                }
                circle = true;
                color[(here + 3) % 6] -= color[here];
                n -= 2 * color[here];
                idx = here;
            }
            else if(color[here] + 1 > color[(here + 3) % 6]){
                ans1 = false;
                break;
            }
            else{
                color[(here + 3) % 6] -= color[here];
                n -= color[here];
            }
        }

        for(int i = 0; ans1 && i < 3; i++)
            if((color[2 * i] && circle) || color[2 * i] > floor(n / 2))
                ans1 = false;

        printf("Case #%d: ", cs);
        if(!ans1)
            printf("IMPOSSIBLE\n");
        else if(!circle){
            while(1){
                bool check = false;

                for(int i = 0; i < 3; i++){
                    int here = 2 * i;
                    if(color[here]){
                        check = true;
                        color[here]--;
                    }
                    printf("%c", ch[here]);
                    for(; color[(here + 3) % 6]; color[(here + 3) % 6]--)
                        printf("%c%c", ch[(here + 3) % 6], ch[here]);
                }
                if(!check)
                    break;
            }
            printf("\n");
        }
        else {
            for(; color[idx]; color[idx]--)
                printf("%c%c", ch[(idx + 3) % 6], ch[idx]);
            printf("\n");
        }
    }

    return 0;
}
