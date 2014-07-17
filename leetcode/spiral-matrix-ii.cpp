#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector< vector<int> > matrix(n, vector<int>(n));
    	int i , j , cnt = 0 ; 
    	for(i = 0 ; i < n/2 + n%2; ++ i){
    		if( i == n - i - 1){
    			matrix[i][i] =  ++cnt;
    		}else if( i < n - i - 1){
    			for(j = i ; j < n - i - 1 ; ++ j)
    				matrix[i][j] = ++ cnt;
    			for(j = i ; j < n - i - 1 ; ++ j)
    				matrix[j][n - i - 1] = ++ cnt;
    			for(j = n - i - 1 ; j > i ; -- j)
    				matrix[n - i - 1][j] = ++ cnt;
    			for(j = n - i - 1 ; j > i ; -- j)
    				matrix[j][i] = ++ cnt;
    		}
    	}
    	assert (cnt == n * n );
    	return matrix;
    }
};


int main(){
	int n ; 
	while(cin >> n){
		Solution sol;
		vector< vector<int> > res = sol.generateMatrix(n);
		cout << "*********************************************" << endl;
		for(int i = 0 ; i < res.size() ; ++ i){
			for(int j = 0 ; j < res[i].size(); ++ j){
				cout << " " << res[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}