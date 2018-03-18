#include<iostream>
#include<vector>

using namespace std;

int main(){
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        int n, sum = 0;
        int ans = 0;
        cin >> n;
        vector<int> score(n);
        for(int j = 0; j < n; j++){
            cin >> score[j];
            sum += score[j];
        }
        float avg = (float)sum / n;
        for(int j = 0; j < n; j++){
            if((float)score[j] > avg)ans++;
        }
        printf("%.3f%%\n", (float)ans / n * 100);
    }

    return 0;
}
