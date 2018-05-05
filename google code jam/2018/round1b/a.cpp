#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int t, n, l;

double round_num(double num){
    return (double)(int)(num + 0.5);
}

int count(int num){
    int ret = 0;
    double check_num = (num + ret) * 100.0 / n;

    while(round_num(check_num) < check_num){
        ret++;
        check_num = (num + ret) * 100.0 / n;
    }

    return ret;
}

bool comp(int n1, int n2){
    return count(n1) < count(n2);
}

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int left = 0;
        int flag = 1;

        cin >> n >> l;
        vector<int> num(l);

        for(int i = 0; i < l; i++){
            cin >> num[i];
            left += num[i];
        }

        left = n - left;
        int pos = 0;
        flag = count(1) + 1;

        sort(num.begin(), num.end(), comp);

        for(int i = 0; left && i < num.size(); i++){
            int flag2 = count(num[i]);

            if(flag2 >= flag || flag2 > left)
                break;
            num[i] += flag2;
            left -= flag2;
        }

        int sum = 0;
        for(int i = 0; i < num.size(); i++){
            sum += round_num(num[i] * 100.0 / n);
        }

        while(left){
            int next = min(flag, left);
            sum += round_num(next * 100.0 / n);
            left -= next;
        }

        cout << "Case #" << cs << ": " << sum << '\n';
    }

    return 0;
}
