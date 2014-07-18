#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


/*
4 
1 2 6 7
3 5 8 13
4 9 12 14
10 11 15 16
Spiral-Matrix-Extention 2
*/
class Solution{
public:
	bool out(int x, int y, int n, int m){
		return x < 0 || y < 0 || x >= n || y >= m;
	}

	vector<vector<int> > spiralMatrixExtend(int n, int m){
		vector<vector<int> > matrix(n, vector<int>(m));
		int x = 0 , y = 0 , cx, cy, d = 1, cnt = 0;
		while(cnt < n * m){
			matrix[x][y] = ++cnt;
			cx = x - d ; cy = y + d;
			if(out(cx, cy, n, m)){
				if( d == 1){
					if(out(x, y + 1, n, m)){
						cx = x + 1 ; cy = y; 
					}else{
						cx = x ; cy = y + 1;
					}
				}else{
					if(out(x + 1, y, n, m)){
						cx = x ; cy = y + 1;
					}else{
						cx = x + 1; cy = y;
					}
				}
				d = (d == -1 ? 1: -1);
			}
			x = cx ; y = cy;
		}
		return matrix;
	}
};

int main(){
	int n ,m;
	while ( cin >> n >> m){
		Solution sol;
		vector<vector<int> > result = sol.spiralMatrixExtend(n, m);
		cout << "Solution #" << n << endl;
		for(int i = 0 ; i < result.size(); ++ i){
			for(int j = 0 ; j < result[i].size(); ++ j)
				cout << " " << result[i][j] ;
			cout << endl;
		}
	}
	return 0;
}