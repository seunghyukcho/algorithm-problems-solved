#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct point{
    int x, y;
    int num;
};

int main(){
    int t;
    int dir[8][2] = {1, 2, -1, 2, 1, -2, -1, -2, 2, 1, -2, 1, 2, -1, -2, -1};
    cin >> t;
    for(; t > 0; t--){
        int size;
        int startx, starty;
        int endx, endy;

        cin >> size;
        cin >> startx >> starty;
        cin >> endx >> endy;
        
        vector<vector<int> > chess(size, vector<int>(size, 0));
        chess[startx][starty] = 1;

        queue<point> q;
        q.push({startx, starty, 1});

        while(!q.empty()){
            int curx = q.front().x;
            int cury = q.front().y;
            int curr = q.front().num;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                
                if(nextx < 0 || nexty < 0 || nextx >= size || nexty >= size || (chess[nextx][nexty] && chess[nextx][nexty] <= curr + 1))continue;
                
                chess[nextx][nexty] = curr + 1;
                if(nextx != endx || nexty != endy)q.push({nextx, nexty, curr + 1});
            }
        }

        cout << chess[endx][endy] - 1 << '\n';

    }

    return 0;
}
                            
