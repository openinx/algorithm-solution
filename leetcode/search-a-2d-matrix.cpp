class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    	int n , m , l, r, mid, val;
    	n = matrix.size(); m = matrix[0].size();
    	l = 0 ; r = n * m - 1;
    	while(l <= r){
    		mid = (l + r) >> 1;
    		val = matrix[ mid / m ][ mid % m ];
    		if(val == target) return true;
    		if(target < val) 
    			r = mid - 1;
    		else
    			l = mid + 1;
    	}
    	return false;
    }
};
