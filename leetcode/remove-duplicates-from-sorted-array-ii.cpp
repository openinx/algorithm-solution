#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	int i , j = 0;
    	for(i = 0 ; i < n ; ++ i)
    		if(j >= 2 && A[i] == A[j-1] && A[i] == A[j-2]){
    			continue;
    		}else{
    			A[j++] = A[i];
    		}
    	return j;
    }
};

int main(){
	Solution sol;
	int A[] = {1, 1, 1, 2, 2, 2, 3};
	int len = sol.removeDuplicates(A, sizeof(A) / sizeof(int));
	for(int i = 0 ; i < len ; ++ i)
		cout << " " << A[i] << endl;
	return 0;
}