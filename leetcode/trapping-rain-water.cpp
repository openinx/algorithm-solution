#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
    	int i = 0 , j = n - 1, maxl = 0 ,maxr = 0, sum=0;
    	while( i <= j ){
    		maxl = max(maxl, A[i]);
    		maxr = max(maxr, A[j]);
    		if(maxl < maxr){
    			sum += max(maxl - A[i++], 0) ;
    		}else{
    			sum += max(maxr - A[j--], 0) ;
    		}
    	}
    	return sum;
    }
};

int main(){
	Solution sol;
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << sol.trap(A, sizeof(A) / sizeof(int)) << endl;
	return 0;
}