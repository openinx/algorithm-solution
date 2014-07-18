class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	if(matrix.size() == 0 || matrix[0].size() == 0) return;
    	int i, j, n = matrix.size(), m = matrix[0].size(), row = 1, col = 1;
    	for(i = 0 ; i < m ; ++ i) 
    		if(matrix[0][i] == 0) row = 0;
    	for(i = 0 ; i < n ; ++ i)
    		if(matrix[i][0] == 0) col = 0;
    	for(i = 0 ;i < n; ++ i){
    		for(j = 0 ; j < m ; ++ j)
    			if(matrix[i][j] == 0) 
    				matrix[0][j] = matrix[i][0] = 0;
    	}
    	for(i = 1 ; i < n ; ++ i){
    		for(j = 1 ; j < m ; ++j)
    			if(matrix[0][j] == 0 || matrix[i][0] == 0)
    				matrix[i][j] = 0;
    	}
    	if(row == 0)
    		for(i = 0 ; i < m; ++ i) matrix[0][i] = 0;
    	if(col == 0)
    		for(i = 0 ; i < n; ++ i) matrix[i][0] = 0;
    }
};
