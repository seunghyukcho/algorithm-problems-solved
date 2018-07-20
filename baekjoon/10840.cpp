#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Part {
    int start, end;
    long long hash;
};

bool operator<(Part p1, Part p2) { return p1.hash < p2.hash; }

vector<Part> P1;
string s1, s2;
long long table[30];

bool check(int start1, int end1, int start2, int end2) {
    if(end1 - start1 + 1 != end2 - start2 + 1) return false;
    vector<int> count(30, 0);

    for(int i = start1; i <= end1; i++) count[s1[i] - 'a']++;
    for(int i = start2; i <= end2; i++) count[s2[i] - 'a']--;

    for(int i = 0; i <= 'z' - 'a'; i++){
        if(start2 == 2 && end2 == 12) cout << count[i] << ' ';
        if(count[i] != 0) return false;
    }

    return true;
}

void generate_hashtable() {
    long long prime = 1000000007;
    table[0] = prime;
    for(int i = 1; i <= 'z' - 'a'; i++) table[i] = table[i - 1] * prime;
}

int main(){
    ios::sync_with_stdio(false);
    generate_hashtable();

    int ans = 0;
    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++) {
        long long h = 0;
        for(int j = i; j < s1.size(); j++) {
            h += table[s1[j] - 'a'];
            P1.push_back({i, j, h});
        }
    }

    sort(P1.begin(), P1.end());

    for(int i = 0; i < s2.size(); i++) {
        long long h = 0;
        for(int j = i + ans; j < s2.size(); j++) {
            h += table[s2[j] - 'a'];


            int s = 0, e = P1.size() - 1;
            while(s < e) {
                int mid = (s + e) / 2;
                if(P1[mid].hash <= h) s = mid + 1;
                else e = mid;
            }

            int result = e;

            for(; result > 0 && P1[result].hash == h; result--) {
                if(i == 2 && j == 12) cout << P1[result].start - P1[result].end << ' ' << i - j << '\n';
                if(check(P1[result].start, P1[result].end, i, j)) {
                    ans = max(ans, j - i + 1);
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
