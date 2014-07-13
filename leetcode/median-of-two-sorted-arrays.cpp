#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Solution {
public:

	int findkth(int A[], int al, int ar, int B[], int bl, int br, int k){
		//cout << "A[" << al << ".." << ar << "]  " <<  "B[" << bl << ".." << br << "] " <<  k << endl; 
		if(al > ar) return B[bl + k - 1 ];
		if(bl > br) return A[al + k - 1 ];
		int am = (al + ar) / 2 , bm = (bl + br) / 2 , t; 
		t = am - al + bm - bl ; 
		//if(k == t + 1) return min(A[am], B[bm]);
		//if(k == t + 2) return max(A[am], B[bm]);
		//if(k >  t + 2) return findkth(A, am + 1, ar, B , bm + 1, br, k - (t+2));
		//if(k <  t + 1) return findkth(A, al, am - 1, B , bl, bm - 1, k );
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	int t = n + m ; 
    	if( t  % 2  == 0 ) {
    		int x = findkth(A, 0, m - 1, B, 0, n - 1, t/2);
    		int y = findkth(A, 0, m - 1, B, 0, n - 1, t/2 + 1);
    		return (double(x + y)) / 2.0 ; 
    	}else{
    		return findkth(A, 0 , m - 1,  B, 0, n - 1, t / 2 + 1 );
    	}
    }
};

int main(){
	Solution sol ; 
	int A[] = {1, 2 , 5, 6, 234 };
	int B[] = {2, 3 , 4, 5};
	for(int i = 1 ; i <= 9 ; ++ i)
		cout << sol.findkth(A, 0, 4, B, 0, 3, i) << endl ;
	//cout << sol.findMedianSortedArrays(A, 5, B, 4) << endl ;
	return 0 ;
}
