#include <iostream>

using namespace std;

int pow_2(int n);

int hanoi(int n, int from, int to);

int main()
{
    int N;
    cin >> N;

    cout << pow_2(N)-1 << endl;

    hanoi(N,1,3);

    return 0;
}

int pow_2(int n)
{
    if(n == 1) return 2;
    if(n%2 == 0) return pow_2(n/2) * pow_2(n/2);
    return 2 * pow_2(n/2) * pow_2(n/2);
}

int hanoi(int n, int from, int to)
{
    if(n == 1)
    {
        cout << from << " " << to;
        return 0;
    }

    int middle = 1;
    if(from == 1 || to == 1) middle = 2;
    if((from == 1 || to == 1)&&(from == 2 || to == 2)) middle = 3;
    hanoi(n - 1, from, middle);
    cout << endl << from << " " << to << endl;
    hanoi(n - 1, middle, to);
    cout << '\n';
    
    return 0;
}
