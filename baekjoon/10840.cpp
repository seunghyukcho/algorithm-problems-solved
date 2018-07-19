#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Part {
    int start, end;
    long long hash;
};

bool comp(Part p1, Part p2) { return p1.hash < p2.hash; }

vector<Part> P1, P2;
string s1, s2;
long long table[30];

bool check(int start1, int end1, int start2, int end2) {
    vector<int> count(30, 0);

    for(int i = start1; i <= end1; i++) count[s1[i] - 'a']++;
    for(int i = start2; i <= end2; i++) count[s2[i] - 'a']--;

    for(int i = 0; i <= 'z' - 'a'; i++)
        if(count[i] != 0) return false;

    return true;
}

void generate_hashtable() {
    long long prime = 1000000007;
    table[0] = prime;
    for(int i = 1; i <= 'z' - 'a'; i++) table[i] = table[i - 1] * prime;
}

int main(){
    int ans = 0;
    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++) {
        long long h = 0;
        for(int j = i; j < s1.size(); j++) {
            h += table[s1[j] - 'a'];
            P1.push_back({i, j, h});
        }
    }

    for(int i = 0; i < s2.size(); i++) {
        long long h = 0;
        for(int j = i; j < s2.size(); j++) {
            h += table[s2[j] - 'a'];
            P2.push_back({i, j, h});
        }
    }

    sort(P1.begin(), P1.end(), comp);
    sort(P2.begin(), P2.end(), comp);

    for(int start1 = 0, start2 = 0; start1 < P1.size() && start2 < P2.size();) {
        if(P1[start1].hash == P2[start2].hash) {
            long long h = P1[start1].hash;

            int i, j;

            for(i = start1; i < P1.size() && h == P1[i].hash; i++)
                for(j = start2; j < P2.size() && h == P2[j].hash; j++) {
                    if(check(P1[i].start, P1[i].end, P2[j].start, P2[j].end)) ans = max(ans, P1[i].end - P1[i].start + 1);
                }

            start1 = i;
            start2 = j;
        } else if(P1[start1].hash > P2[start2].hash) start2++;
        else start1++;
    }

    cout << ans << '\n';
    return 0;
}
