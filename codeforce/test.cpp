#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class SoManyRectangles{
public:
	bool connected(pair<int, int> x1, pair<int, int> y1, pair<int, int> x2, pair<int, int> y2){
		
	}
	
	int maxOverlap(vector<int> x1, vector<int> y1, vector<int> x2, vector<int> y2) {
		int ret = 0;
		
		int board[1000000][1000000] = {0};
		int mid = 5000;
		
		for(int i = 0; i < x1.size(); i++){
			for(int x = x1[i] + 1; x < x2[i]; x++){
				for(int y = y1[i] + 1; y < y2[i]; y++){
					board[x + mid][y + mid]++;
					ret = max(ret, board[x + mid][y + mid]);
				}
			}
		}
		
		return ret;
	}
};


int main(){
	
	return 0;
}
