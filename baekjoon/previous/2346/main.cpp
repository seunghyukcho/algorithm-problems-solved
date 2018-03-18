#include<iostream>
#include<list>

using namespace std;

int main(){
    int n, i;
    cin >> n;

    list<pair<int,int> > b;

    for(i = 0; i < n; i++){
        int num;
        cin >> num;
        b.push_back(make_pair(i+1, num));
    }

    auto it = b.begin();
    for(i = 0; i < n-1; i++){
        cout << it->first << ' ';
        int num = it->second;
        if(num > 0){
            auto temp = it;
            temp++;
            if(temp == b.end())temp = b.begin();
            b.erase(it);
            num--;
            it = temp;
            while(num > 0){
                it++;
                if(it == b.end())it = b.begin();
                num--;
            }
        }
        else{
            auto temp = it;
            if(temp == b.begin())temp = b.end();
            temp--;
            b.erase(it);
            num++;
            it = temp;
            while(num < 0){
                if(it == b.begin())it = b.end();
                it--;
                num++;
            }
        }
    }
    
    cout << b.front().first << '\n';
    return 0;
}

