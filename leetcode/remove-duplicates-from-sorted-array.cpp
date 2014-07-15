#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if( n == 0 ) return 0 ;
    	int i , j = 0;
    	for(i = 1 ; i < n; ++ i)
    		if(A[i] != A[j]){
    			A[++j] = A[i];
    		}
    	return ++j;
    }
};

int main(){
	Solution sol;


}