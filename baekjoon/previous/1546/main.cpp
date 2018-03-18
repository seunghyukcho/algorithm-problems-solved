#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, sum = 0;
    int max = 0;
    cin >> n;
    vector<int> score(n);
    for(int i = 0; i < n; i++){
        cin >> score[i];
        sum += score[i];
        max = max > score[i] ? max : score[i];
    }
    
    float ans =  (float)sum / n * 100 / max;
    printf("%.2f\n", ans);

    return 0;
}

