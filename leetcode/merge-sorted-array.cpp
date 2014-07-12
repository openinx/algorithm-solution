class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int i, j , k; 
    	for(i=m-1; i>=0; --i) A[n+i] = A[i];
    	i = n, j = 0 , k = 0; 
    	while(i<n+m && j<n){
    		if(A[i] < B[j]) A[k++] = A[i++] ; 
    		else A[k++] = B[j++];
    	}
    	while(i<n+m) A[k++] = A[i++] ; 
    	while(j<n) A[k++] = B[j++] ;
    }
};