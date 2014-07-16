#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
	bool canReach(set<int> &iset, int index){
		return (iset.upper_bound(index) != iset.end() || iset.find(index) != iset.end());
	}
    bool canJump(int A[], int n) {
    	set<int> iset;
    	if(n == 0) return true;
    	iset.insert(A[0] + 1);
    	for(int i = 1; i < n ;++ i){
    		if(canReach(iset, i+1)){
    			iset.insert(i+1+A[i]);
    		}
    	}
    	return canReach(iset, n);
    }
};

int main(){
	Solution sol;
	int a[] = {2,3,1,1,4};
	cout << sol.canJump(a, sizeof(a) / sizeof(int)) << endl;
	return 0;
}