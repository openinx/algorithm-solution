#include<algorithm>
#include<vector>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// class Solution {
// public:
//     bool isMatch(const char *s, const char *p) {
//     	int n = strlen(s), m = strlen(p) ; 
//     	vector< vector <int> > dp(n+1) ; 
//     	for(int i = 0 ; i <= n ; ++ i) {
//     		dp[i] = vector<int>(m+1);
//     		for(int j = 0 ; j <= m ; ++ j) 
//     			dp[i][j] = 0 ; 
//     	}
//     	dp[0][0] = 1 ;
//     	for(int i = 1 ; i <= m ; ++ i) dp[0][i] = dp[0][i-1] & (p[i-1] == '*');
//     	for(int i = 1 ; i <= n ; ++ i) dp[i][0] = dp[i-1][0] & (s[i-1] == '*') ; 
//     	for(int i = 1 ; i <= n ; ++ i)
//     		for(int j = 1 ; j <=m ; ++ j){
//     			if(p[j-1] == '*')
//     				dp[i][j] = dp[i-1][j] | dp[i][j-1];
//     			else if(p[j-1] == '?')
//     				dp[i][j] = dp[i-1][j-1];
//     			else if(s[i-1] == p[j-1]) 
//     				dp[i][j] = dp[i-1][j-1];
//     		}
//     	return dp[n][m];
//     }
// };

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	int n = strlen(s), m = strlen(p) ; 
    	vector<int> dp(m+1), prev(m+1); 
    	for(int i = 0 ; i <= m ; ++ i) dp[i] = 0 ; 
    	prev[0] = 1 ;
    	for(int i = 1 ; i <= m ; ++ i)
    		prev[i] = prev[i-1] & (p[i-1] == '*');
    	for(int i = 1 ; i <= n ; ++ i){
    		for(int j = 0 ; j <=m ; ++ j){
    			if(j == 0 ) { 
    				dp[0] = prev[0] & (s[i-1] == '*');
    				continue;
    			}
    			if(p[j-1] == '*')
    				dp[j] = prev[j] | dp[j-1];
    			else if(p[j-1] == '?')
    				dp[j] = prev[j-1];
    			else if(s[i-1] == p[j-1]) 
    				dp[j] = prev[j-1];
    			else 
    				dp[j] = 0 ;
    		}
    		for(int j = 0 ;j <=m ; ++ j)
    			prev[j] = dp[j];
    	}
    	return prev[m];
    }
};


int main(int argc, char ** args){
	char a[] = "ab", b[] = "&";
    Solution sol ; 
    cout << sol.isMatch(a, b) << endl ;
	/*while(scanf("%s%s", a, b) !=EOF ){
		Solution sol ; 
		cout << sol.isMatch(a, b) << endl ;
	}*/
	return 0 ;
}