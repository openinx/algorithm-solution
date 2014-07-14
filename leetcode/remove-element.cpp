class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	int i , j = 0 ; 
    	for(i = 0 ; i < n ; ++ i)
    		if(A[i] ! = elem)
    			A[j++] = A[i];
    	return j;
    }
};