#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

map<string,pair<int,int>> place;
map<string, int> station;
map<string, pair<int, double> > customer; 

int nowx, nowy;

void getinput(){
    string nowp="";
    string tmp;

    do {
        cin >> tmp;
        if(tmp[0] >= '0' && tmp[0] <= '9') break;
        nowp=nowp+" "+tmp;
    } while(1);

    int x=0;
    for(int i=0;i<tmp.size();i++){
        x*=10;
        x+=tmp[i]-'0';
    }
    int y;
    cin >> y;
    
    if(nowp==" Taxi Garage"){
        nowx=x;
        nowy=y;   
    }
    place[nowp]=make_pair(x,y);

}
void getstation(){
    string nowp="";
    string tmp;

    do {
        cin >> tmp;
        if(tmp[0] >= '0' && tmp[0] <= '9') break;
        nowp=nowp+" "+tmp;
    } while(1);
    int p=0;
    for(int i=0;i<tmp.size();i++){
        p*=10;
        p+=tmp[i]-'0';
    }

    station[nowp]=p;
}

int dist(int x1,int y1,int x2,int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
    double fuel,mon,go;
    cin >> fuel >> mon >> go;
    double nowfuel=fuel;
    int pass=0;
    int money=0;
    int n;
    cin >> n;
    while(n--){
        getinput();
    }
    int m=3;
    while(m--){
        getstation();
    }
    int comm;
    cin >> comm;
    
    while(comm--){
        string tmp;
        cin >> tmp;
        if(tmp=="Go"){
            cin>>tmp;
            string pl="";
            do{
                cin >> tmp;
                pl=pl+" "+tmp;
            } while(tmp.back()!='.');
            pl.pop_back();
            
            int nowdist=dist(place[pl].first,place[pl].second,nowx,nowy);
            nowfuel -= nowdist / go;
            
            nowx = place[pl].first, nowy = place[pl].second;
            if(nowfuel<0){
                cout << "OUT OF GAS\n";
                return 0;
            }
        
            for(auto& here : customer) {
                here.second.second += here.second.first*nowdist;
            }

            if(customer[pl].first!=0){
                money += (int)(customer[pl].second * mon);
                pass-=customer[pl].first;
                customer[pl].first=0;
                customer[pl].second=0;
            }

            if(station[pl] != 0){
                int result = (fuel - nowfuel) * station[pl] + 1e-10;
                if(result <= money){
                    money = money - result;
                    nowfuel=fuel;
                }
                else{
                    nowfuel+=money/station[pl];
                    money=0;
                }
            }
        }
        else{
            for(int i=0;i<4;i++) cin >>tmp;
            string pl="";
            do{
                cin >> tmp;
                pl=pl+" "+tmp;
            }while(tmp.back()!='.');
            pl.pop_back();
            pass++;
            if(pass>3){
                cout <<"CAPACITY FULL\n";
                return 0;
            }
            customer[pl].first++;
            if(customer[pl].first == 1) customer[pl].second = 0;
        }
    }
    if(!(place[" Taxi Garage"].first==nowx &&place[" Taxi Garage"].second == nowy)){
        cout << "NOT IN GARAGE\n";
        return 0;
    }
    if(pass!=0){
        cout << "REMAINING PASSENGER\n";
        return 0;
    }
    cout << money <<endl;
}