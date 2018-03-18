#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

float dist(int x1, int y1, int x2, int y2);
float angle(int x1, int y1, int x2, int y2);
int ccw(int x1, int y1, int x2, int y2);

int main(){
    int n, min, minn;
    cin >> n;
    vector<pair<int, int> > coor(n+1);
    min = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> coor[i].first << coor[i].second;
        if(coor[i].second < min){
            minn = i;
            min = coor[i].second;
        }
    }
    map<float, int> check;
    vector<pair<float, int> > hull;
    int x1 = coor[minn].first;
    int y1 = coor[minn].second;
    for(int i = 1; i <= n; i++){
        if(i == minn)continue;
        
        int x = coor[i].first;
        int y = coor[i].second;

        float ang = angle(x1, y1, x, y);
        if(check.count(ang)){
            float dis = dist(x1, y1, x, y);
            if(dis > dist(x1, y1, coor[check[ang]].first, coor[check[ang]].second))check[ang] = i;
        }
        else check[ang] = i;
    }
    for(auto i = check.begin(); i < check.end(); i++)hull.push_back({i->first, i->second});
    sort(hull.begin(), hull.end());
    hull.push_back({0.0, minn});
    stack<int> s;
    s.push_back(minn);
    for(auto i : hull){
        int x = coor[i].first;
        int y = coor[i].second;
        int x
