class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int n1 = s1.size(), n2 = s2.size(), n3 = s3.size(), i, j; 
    	if( n1+n2 != n3) return false;
    	vector<int> dp(n2+1), prev(n2+1);
    	fill(prev.begin(), prev.end(), 0);
    	prev[0] = 1 ; 
    	for(j = 1 ; j <= n2 ; ++ j) prev[j] = (s3[j-1] == s2[j-1] && prev[j-1]);
    	for(i = 1 ; i <= n1 ; ++ i){
    		dp[0] = (s3[i-1] == s1[i-1] && prev[0]) ; 
    		for(j = 1 ; j <= n2 ; ++ j){
    			dp[j] = ((s3[i+j-1] == s1[i-1] && prev[j]) | (s3[i+j-1]==s2[j-1] && dp[j-1])); 
    		}
    		swap(dp, prev);
    	}
    	return prev[n2];
    }
};