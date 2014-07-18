class Solution {
public:
    void sortColors(int A[], int n) {
    	int r = 0, w = 0 , b = n ; 
    	for( ; w < b ; ){
    		if(A[w] == 0)
    			swap(A[r++], A[w++]);
    		else if(A[w] == 2)
    			swap(A[w], A[--b]);
    		else
    			w++;
    	}
    }
};