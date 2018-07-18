#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        if(x1 == x2) {
            if(x3 == x4) {
                if(x1 == x3) printf("LINE\n");
                else printf("NONE\n");
            } else {
                double a = (y4 - y3) / (x4 - (double)x3);
                double b = y4 - a * x4;

                printf("POINT %.2f %.2f\n", (double)x1, a * x1 + b);
            }
        } else if(x3 == x4) {
            double a = (y2 - y1) / (x2 - (double)x1);
            double b = y2 - a * x2;

            printf("POINT %.2f %.2f\n", (double)x3, a * x3 + b);
        } else {
            double a1 = (y4 - y3) / (x4 - (double)x3);
            double b1 = y4 - a1 * x4;

            double a2 = (y2 - y1) / (x2 - (double)x1);
            double b2 = y2 - a2 * x2;

            if(a1 == a2) {
                if(b1 == b2) printf("LINE\n");
                else printf("NONE\n");
            } else {
                double x = (b1 - b2) / (a2 - a1);
                double y = a1 * x + b1;

                printf("POINT %.2f %.2f\n", x, y);
            }
        }
    }

    return 0;
}
