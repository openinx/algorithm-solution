#include <iostream>

using namespace std; 

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	int left = 0 , right = n-1, mid ; 
    	if(n == 0 ) return 0;
    	while( left <= right ){
    		mid = (left + right) >> 1 ; 
    		if(A[mid] == target )
    			return mid ;
    		else if(target < A[mid])
    			right = mid - 1 ; 
    		else if(target >  A[mid])
    			left = mid + 1 ; 
    		else
    			break; 
    	}
    	return (target < A[mid]) ? mid : mid + 1 ; 
    }
};

int main(){
	Solution sol ; 
	int a[] = {1, 3, 5, 6} ; 
	cout << sol.searchInsert(a, 4, 5 ) << endl ;
	cout << sol.searchInsert(a, 4, 2 ) << endl ;
	cout << sol.searchInsert(a, 4, 7 ) << endl ;
	cout << sol.searchInsert(a, 4, 0 ) << endl ;
	return 0 ;
}