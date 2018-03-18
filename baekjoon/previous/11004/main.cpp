#include<iostream>

using namespace std;

int num[5000002];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    int start = 0;
    int end = n - 1;
    k--;

    while(start < end){
        int l = start;
        int r = end;
        int pivot = num[l];
        l++;
        while(l <= r){
            while(pivot >= num[l] && l <= end)
                l++;
            while(pivot <= num[r] && r >= start + 1)
                r--; 

            if(l <= r){
                swap(num[l], num[r]);
            }
        }

        swap(num[start], num[r]);
        
        if(r == k)
            break;
        else if(r > k)
            end = r - 1;
        else
            start = r + 1;
    }

    printf("%d\n", num[k]);

    return 0;
}
