#include<iostream>
#include<vector>

using namespace std;

int t, r, c, h, v;
char waffle[102][102];
int choco[102][102];

bool answer(){
    vector<int> cut(1, 0);
    vector<int> cut2(1, 0);

    if(choco[r][c] % (h + 1) * (v + 1))
        return false;
    for(int i = 1; i <= r; i++){
        if(cut.size() == h + 1){
            if(choco[r][c] - choco[cut.back()][c] != choco[r][c] / (h + 1))
                return false;
            cut.push_back(r);
            break;
        }
        else if(choco[i][c] - choco[cut.back()][c] == choco[r][c] / (h + 1))
            cut.push_back(i);
        else if(choco[i][c] - choco[cut.back()][c] > choco[r][c] / (h + 1))
            return false;

    }

    if(cut.size() != h + 2)
        return false;
    for(int i = 1; i <= c; i++){
        if(cut2.size() == v + 1){
            for(int j = 2; j < cut.size(); j++){
                int check = choco[cut[j]][c] - choco[cut[j - 1]][c] - choco[cut[j]][cut2.back()] + choco[cut[j - 1]][cut2.back()];

                if(check != choco[r][c] / ((h + 1) * (v + 1)))
                    return false;
            }
            cut2.push_back(c);
            break;
        }
        else if(choco[cut[1]][i] - choco[cut[1]][cut2.back()] == choco[r][c] / ((h + 1) * (v + 1))){
            bool put = true;
            for(int j = 2; j < cut.size(); j++){
                int check = choco[cut[j]][i] - choco[cut[j - 1]][i] - choco[cut[j]][cut2.back()] + choco[cut[j - 1]][cut2.back()];
                
                if(check != choco[r][c] / ((h + 1) * (v + 1))){
                    put = false;
                    break;
                }
            }
            if(put)
                cut2.push_back(i);
        }
        else if(choco[cut[1]][i] - choco[cut[1]][cut2.back()] > choco[r][c] / ((h + 1) * (v + 1)))
            return false;

    }
    if(cut2.size() != v + 2)
        return false;

    return true;
}

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> r >> c >> h >> v;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                cin >> waffle[i][j];
                choco[i][j] = choco[i - 1][j] + choco[i][j - 1] - choco[i - 1][j - 1];

                if(waffle[i][j] == '@')
                    choco[i][j]++;
            }
        }
        printf("Case #%d: %s\n", cs, (answer() ? "POSSIBLE" : "IMPOSSIBLE"));
    }
    return 0;
}
