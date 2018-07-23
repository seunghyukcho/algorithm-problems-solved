#include<iostream>
#include<cmath>

using namespace std;

int main(){
    for(int i = 1;;i++) {
        int r, w, h;
        cin >> r;
        if(r == 0) break;
        cin >> w >> h;
        double result = sqrt(pow(w / 2.0, 2) + pow(h / 2.0, 2));
        cout << "Pizza " << i << (result <= (double)r ? " fits on the table.\n" : " does not fit on the table.\n");
    }
    return 0;
}
