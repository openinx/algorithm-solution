#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	if(triangle.size() == 0 ) return 0 ;
    	vector<int> dp(triangle.back().begin(), triangle.back().end());
    	for(int i = triangle.size()-2 ; i >= 0 ; --i ){
    		for(int j = 0 ; j < triangle[i].size(); ++ j){
    			dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
    		}
    	}
    	return dp[0];
    }
};

int main(){
	Solution sol ; 
	vector< vector<int> > triangle;
	int a0[] = {2};
	vector<int> v0(a0, a0 + sizeof(a0) / sizeof(int));
	triangle.push_back(v0);

	int a1[] = {3, 4};
	vector<int> v1(a1, a1 + sizeof(a1) / sizeof(int));
	triangle.push_back(v1);


	int a2[] = { 6,5,7 };
	vector<int> v2(a2, a2 + sizeof(a2) / sizeof(int));
	triangle.push_back(v2);

	int a3[] = {4,1,8,3};
	vector<int> v3(a3, a3 + sizeof(a3) / sizeof(int));
	triangle.push_back(v3);

	cout << sol.minimumTotal(triangle) << endl; 
}