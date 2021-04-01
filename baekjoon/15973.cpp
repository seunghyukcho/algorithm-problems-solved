#include <stdio.h>
int x1, x2, y1, y2, x3, x4, y3, y4; 

int main() {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

    if(x1 == x4 && y1 == y4) printf("POINT\n");
    else if(x2 == x3 && y1 == y4) printf("POINT\n");
    else if(x2 == x3 && y2 == y3) printf("POINT\n");
    else if(x1 == x4 && y2 == y3) printf("POINT\n");
    else if((y1 == y4 || y2 == y3) && !(x2 < x3 || x4 < x1)) printf("LINE\n");
    else if((x2 == x3 || x1 == x4) && !(y2 < y3 || y4 < y1)) printf("LINE\n");
    else if(x2 < x3) printf("NULL\n");
    else if(y2 < y3) printf("NULL\n");
    else if(x4 < x1) printf("NULL\n");
    else if(y4 < y1) printf("NULL\n");
    else printf("FACE");

    return 0;
}
