#include<iostream>
#include<deque>

using namespace std;

int main(){
    int n, w, l;
    int truck;
    cin >> n >> w >> l;
    
    int ans = w;
    deque<int> bridge;
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> truck;
        if(bridge.size() < w && sum + truck <= l){
            sum += truck;
            bridge.push_back(truck);
            ans++;
        }
        else if(bridge.size() == w || sum + truck > l){
            int tot = w - bridge.size();
            while(bridge.size() == w || sum + truck > l){
                tot++;
                sum -= bridge.front();
                bridge.pop_front();
            }
            ans += tot;
            bridge.push_back(truck);
            sum += truck;
        }
    } 
    
    cout << ans << '\n';
      
    return 0;
}


