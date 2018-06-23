#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> palin;

void make_palin(){
    for(int i = 1; i < 10; i++)
        palin.push_back(i);

    for(int i = 1; i < 10; i++){
        palin.push_back(i * 11);
        for(int j = 0; j < 10; j++){
            palin.push_back(i * 101 + j * 10);
            palin.push_back(i * 1001 + j * 110);
        }
    }

    sort(palin.begin(), palin.end());
}

bool check_palin(int n){
    vector<int> check;
    for(; n > 0; n /= 10)
        check.push_back(n % 10);

    for(int i = 0; i < check.size() / 2; i++)
        if(check[i] != check[check.size() - i - 1])
            return false;

    return true;
}

int main(int argc, char** argv)
{
	int T, test_case;

    make_palin();

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		int start = 0, end = palin.size() - 1, pick = -1;

		cin >> n;
        cout << "Case #" << test_case + 1 << endl;

        if(check_palin(n))
            cout << 1 << ' ' << n << '\n';
        else{
            while(pick == -1 && start <= end){
                int here = n - palin[start] - palin[end];

                if(here < 0)
                    end--;
                else if(here == 0)
                    pick = palin[start];
                else
                    start++;
            }

            if(pick != -1){
                cout << 2 << ' ' << palin[end] << ' ' << pick << '\n';
                continue;
            }

            start = 0; end = palin.size() - 1;
            while(pick == -1 && start <= end){
                int here = n - palin[start] - palin[end];

                if(here < 0)
                    end--;
                else if(check_palin(here)){
                    pick = here;
                }
                else
                    start++;
            }

            if(pick != -1)
                cout << 3 << ' ' << palin[end] << ' ' << pick << ' ' << palin[start] << '\n';
            else
                cout << 0 << '\n';
        }

	}

	return 0;
}
