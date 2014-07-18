#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Solution {
public:
	int findkth(int A[], int m , int B[], int n, int k){
		if(m > n) return findkth(B, n , A, m , k);
		if(m == 0) return B[k-1];
		if(k == 1) return min(A[0], B[0]);
		int pa = min(k/2, m), pb = k - pa;
		if(A[pa-1] < B[pb-1])
			return findkth(A + pa, m - pa ,B, n, k - pa);
		if(A[pa-1] > B[pb-1])
			return findkth(A, m , B + pb, n - pb, k - pb);
		return A[pa-1];
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if( (n+m) % 2 == 0 ) {
    		return (findkth(A, m, B, n , (m+n)/2) + findkth(A, m, B, n, (m+n)/2 + 1)) * 0.5;
    	}else{
    		return findkth(A, m, B, n, (m + n)/2 + 1);
    	}
    }
};

int main(){
	Solution sol ; 
	//int A[] = {1, 2 , 5, 6, 234};
	//int B[] = {2, 3 , 4, 5};
	int A[] = {};
	int B[] = {2, 3};
	cout << sol.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)) << endl ;
	return 0 ;
}
