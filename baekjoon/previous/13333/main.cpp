#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    vector<int> paper;

    cin >> n;

    int max_p = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        max_p = max(max_p, num);
        paper.push_back(num);
    }
    sort(paper.begin(), paper.end());

    int r = 0; 
    int l = max_p;
    int ans;
    
    while(r <= l){
        int mid = (r + l) / 2;
        int count1 = 0;
        int count2 = 0;
        
        for(int i = 0; i < n; i++){
            if(paper[i] > mid)
                count1++;
            else if(paper[i] == mid)
                count2++;
        }
        if(count1 == mid || (count1 < mid && count1 + count2 >= mid)){
            ans = mid;
            break;
        }
        else if(count1 > mid)
            r = mid + 1;
        else
            l = mid - 1;
    }

    cout << ans << '\n';

    return 0;
}

