class Solution {
public:
    int maxSubArray(int A[], int n) {
    	if(n == 0) return 0;
    	int i ,j, dp, maxval; 
    	maxval = dp = A[0];
    	for(i = 1 ; i < n; ++ i){
    		dp = max(A[i], dp + A[i]);
    		maxval = max(dp, maxval);
    	}
    	return maxval;
    }
};