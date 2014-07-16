#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
    	int maxpos = 0;
    	vector<int> dp(n);
    	fill(dp.begin(), dp.end(), -1);
    	dp[0] = 0 ; 
    	for(int i = 0 ; i < n ; ++ i){
    		if(dp[i] == -1) continue;
    		for(int j = maxpos + 1; j < dp.size() && j <= i+A[i]; ++ j){
    			dp[j] = (dp[j] == -1 ? dp[i] + 1 : min(dp[i]+1, dp[j]));
    			if(j == n - 1)  return dp[n-1];
    			maxpos = max(maxpos, i+A[i]);
    		}
    	}
    	return dp[n-1];
    }
};

int main(){
	int n , x; 
	while(cin >>n ){
		int *A = new int[n];
		for(int i = 0 ; i < n ; ++ i){
			cin >> x ; 
			A[i] = x ;
		}
		Solution sol;
		cout << sol.jump(A, n) << endl;
		delete A;
	}
	return 0;
}