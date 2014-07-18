#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int i , j , k, ans = 1, start = 0, n = s.size();
    	if(n == 0) return "";
    	for(i = 0 ; i < n ; ++ i) dp[i][i] = 1;
    	for(i = 1 ; i < n ; ++ i) dp[i][i-1] = 1;
    	for(k = 1 ; k < n ; ++ k){
    		for(i = 0 ; i + k < n; ++ i){
    			j = i + k; 
    			dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
    			if(dp[i][j] && (j - i + 1 > ans)){
    				ans = j - i + 1;
    				start = i; 
    			}
    		}
    	}
    	return s.substr(start, ans);
    }
private:
	int dp[1002][1002];
};

int main(){
	string s ;
	while(cin >> s){
		Solution sol;
		cout << sol.longestPalindrome(s)<< endl;
	}
	return 0;
}