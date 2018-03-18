#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct stu{
    int num;
    int score[4];
    int sum = 0;
};

bool cmp(stu a, stu b){
    return (a.sum > b.sum || (a.sum == b.sum && (a.score[1] > b.score[1] || (a.score[1] == b.score[1] && a.score[2] > b.score[2]))));
}

int main(){
    int n;
    vector<stu> ans(3);
    cin >> n;
    for(int i = 0; i < n; i++){
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        ans[0].score[n1]++;
        ans[0].sum += n1;
        ans[1].score[n2]++;
        ans[1].sum += n2;
        ans[2].score[n3]++;
        ans[2].sum += n3;
    }
    ans[0].num = 1;
    ans[1].num = 2;
    ans[2].num = 3;

    sort(ans.begin(), ans.end(), cmp);
    if(ans[0].score[3] == ans[1].score[3])cout << 0 << ' ' << ans[0].sum << '\n';
    else cout << ans[0].num << ' ' << ans[0].sum << '\n';

    return 0;
}
