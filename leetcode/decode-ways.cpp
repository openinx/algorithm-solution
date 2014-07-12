class Solution {
public:
    int numDecodings(string s) {
    	if(s.size() <= 0) return 0 ;
    	vector<int> dp(s.size());
    	fill(dp.begin(), dp.end(), 0); 
    	dp[0] = (s[0]<='9' && s[0] >= '1');
    	for(int i = 1 ; i < s.size(); ++ i){
    		if(s[i]<='9' && s[i] >= '1') dp[i] += dp[i-1] ;
    		int val = (s[i-1]-'0')*10 + (s[i]-'0');
    		if(val >= 10 && val <= 26){
    			dp[i] += (i>=2 ? dp[i-2]: 1);
    		}
    	}
    	return dp[s.size()-1];
    }
};