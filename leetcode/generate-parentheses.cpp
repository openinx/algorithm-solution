#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:

	vector<string> solve(int n, vector< vector<string> > & dp, vector<bool> &visited){
		if(visited[n]) return dp[n];
		dp[n] = vector<string>();
		for(int i = 0 ; i < n ; ++ i){
			vector<string> left = solve(i, dp, visited);
			vector<string> right = solve(n-1-i, dp, visited);
			for(int a = 0 ; a < left.size(); ++ a)
				for(int b = 0 ; b < right.size(); ++ b)
					dp[n].push_back("(" + left[a] + ")" + right[b]);
		}
		visited[n] = true;
		return dp[n];
	}

    vector<string> generateParenthesis(int n) {
    	vector< vector<string> > dp(n+1);
    	vector<bool> visited(n+1);
    	fill(visited.begin(), visited.end(), false);
    	visited[0] = true; dp[0] = vector<string>(); dp[0].push_back("");
    	visited[1] = true; dp[1] = vector<string>(); dp[1].push_back("()");
    	return solve(n, dp, visited);
    }
};

int main(){
	Solution sol ;
	vector<string> dp = sol.generateParenthesis(10);
	for(int i = 0 ; i < dp.size(); ++ i)
		cout << dp[i] << endl;
	return 0;
}