#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int pivot;
    cout << "? " << 1 << ' ' << n << '\n';
    cout.flush();
    cin >> pivot;

    int start, end;
    if(pivot == n) {
        start = 1;
        end = n - 1;
    }
    else if(pivot == 1) {
        start = 2;
        end = n;
    }
    else {
        cout << "? " << 1 << ' ' << pivot << '\n';
        cout.flush();

        int l;
        cin >> l;
        if(l == pivot) {
            start = 1;
            end = pivot - 1;
        }
        else {
            start = pivot + 1;
            end = n;
        }
    }

    while(start + 1 < end) {
        int mid = (start + end) / 2, num;
        if(mid < pivot) {
            cout << "? " << mid << ' ' << pivot << '\n';
        }
        else {
            cout << "? " << pivot << ' ' << mid << '\n';
        }

        cout.flush();
        cin >> num;

        if(num == pivot) (mid < pivot ? start : end) = mid;
        else {
            if(mid < pivot) end = mid - 1;
            else start = mid + 1;
        }
    }

    if(start + 1 == end) {
        int num;
        if(start < pivot) cout << "? " << end << ' ' << pivot << '\n';
        else cout << "? " << pivot << ' ' << start << '\n';

        cout.flush();
        cin >> num;

        if(num == pivot) start < pivot ? start++ : end--;
        else start < pivot ? end-- : start++;
    }

    cout << "! " << start << '\n';
}
