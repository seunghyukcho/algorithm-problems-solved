#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string input;
vector<vector<int> > counting('z' - 'a' + 2);
vector<int> num;

void suffix_sort(int start, int end, int here){
    if(start >= end)
        return;

    for(int i = 0; i <= 'z' - 'a' + 1; i++)
        counting[i].clear();

    for(int i = start; i <= end; i++){
        if(here + num[i] >= input.size())
            counting[0].push_back(num[i]);
        else
            counting[input[num[i] + here] - 'a' + 1].push_back(num[i]);
    }

    int n = start;
    for(int i = 0; i <= 'z' - 'a' + 1; i++){
        for(auto here : counting[i])
            num[n++] = here;
    }

    int s = start;
    for(int i = start + 1; i <= end; i++){
        if(num[i - 1] + here < input.size()){
            if(input[num[i - 1] + here] != input[num[i] + here]){
                suffix_sort(s, i - 1, here + 1);
                s = i;
            }
            else if(i == end)
                suffix_sort(s, i, here + 1);
        }
        else
            s++;
    }
}

int main(){
    cin >> input;

    for(int i = 0; i < input.size(); i++)
        num.push_back(i);
    

    suffix_sort(0, input.size() - 1, 0);

    vector<int> rank(input.size()), lcp(input.size());
    for(int i = 0; i < input.size(); i++){
        rank[num[i]] = i;
        cout << num[i] + 1 << ' ';
    }
    cout << "\n" ;

    int len = 0;

    for(int i = 0; i < input.size(); i++){
        int k = rank[i];
        if (k){
            int j = num[k - 1];

            while (input[j + len] == input[i + len])
                len++;

            lcp[k] = len;

            if (len)
                len--;
        }
    }

    for(int i = 0; i < input.size(); i++){
        if(!i)
            cout << "x ";
        else
            cout << lcp[i] << ' ';
    }

    cout << '\n';

    return 0;
}
