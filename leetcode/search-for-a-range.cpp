#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> ans(2, -1);
    	int l = 0 , r = n - 1, mid ;
    	while(l <= r){
    		mid = (l + r) >> 1;
    		if(A[mid] == target){
    			ans[0] = mid; r = mid - 1;
    		}else if(target < A[mid]){
    			r = mid - 1 ;
    		}else{
    			l = mid + 1 ;
    		}
    	}
    	l = 0 ; r = n - 1;
    	while(l <= r){
    		mid = (l + r) >> 1;
    		if(A[mid] == target){
    			ans[1] = mid; l = mid + 1;
    		}else if(target < A[mid]){
    			r = mid - 1 ;
    		}else{
    			l = mid + 1 ;
    		}
    	}
    	return ans;
    }
};

int main(){
	Solution sol;
	int a[]  = {5, 7, 7, 8, 8, 10};
	vector<int> ans ;
	ans = sol.searchRange(a, sizeof(a) / sizeof(int), 8);
	cout << "[ " << ans[0] <<  "," << ans[1] << "]"<< endl;
	ans = sol.searchRange(a, sizeof(a) / sizeof(int), 7);
	cout << "[ " << ans[0] <<  "," << ans[1] << "]"<< endl;
	ans = sol.searchRange(a, sizeof(a) / sizeof(int), 4);
	cout << "[ " << ans[0] <<  "," << ans[1] << "]"<< endl;
	return 0;
}