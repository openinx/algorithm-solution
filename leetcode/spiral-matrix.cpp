#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> result;
    	if(matrix.size() == 0 || matrix[0].size() == 0) return result;
    	int i, j , n = matrix.size() , m = matrix[0].size();
    	for(i = 0 ; i <= min(n/2, m/2); ++ i){
    		if( i == m - i - 1){
    			for(j = i ; j <= n - i - 1 ; ++ j) 
    				result.push_back(matrix[j][i]);
    		}else if( i == n - i - 1 ){
    			for(j = i ; j <= m - i - 1 ; ++ j)
    				result.push_back(matrix[i][j]);
    		}else if(i < m - i -1 && i < n - i - 1){
	    		for(j = i ; j < m - i - 1 ; ++ j)
	    			result.push_back(matrix[i][j]);
	    		for(j = i ; j < n - i - 1 ; ++ j)
	    			result.push_back(matrix[j][m-i-1]);
	    		for(j = m - i - 1 ; j > i ; -- j)
	    			result.push_back(matrix[n-i-1][j]);
	    		for(j = n - i - 1 ; j > i ; -- j)
	    			result.push_back(matrix[j][i]);
    		}
    	}
    	return result;
    }
};

int main(){
	int n ;
	int a[][10] = {
		{1,2,3,4,5,6,7,8,9,10},
		{11,12,13,14,15,16,17,18,19,20},
	};
	vector< vector<int> > matrix ;
	for(int i = 0 ; i < sizeof(a) / sizeof(a[0]) ; ++ i)
		matrix.push_back(vector<int>(a[i], a[i] + sizeof(a[i]) / sizeof(int) ));
	Solution sol;
	vector<int> ans =  sol.spiralOrder(matrix) ;
	for(int i = 0 ; i < ans.size() ; ++ i)
		cout << " " << ans[i] ;
	cout << endl;
	return 0;
}