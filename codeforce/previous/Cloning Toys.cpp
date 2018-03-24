#include<iostream>

using namespace std;

int x, y;

int main(){
	cin >> x >> y;
	
	if(y == 0)
		printf("NO");
	else if(y == 1){
		if(x > 0)
			printf("NO");
		else
			printf("YES");
	}
	else if(x < y - 1)
		printf("NO");
	else if((x - y + 1) % 2)
		printf("NO");
	else
		printf("YES");
	
	return 0;
}
