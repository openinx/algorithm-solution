#define unordered_set set
#define unordered_map map


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.size() == 0 ) return 0;
    	unordered_set<char> uset;
    	int i = 0 , j = 0, ans = 1; 
    	uset.insert(s[0]);
    	for(j = 1 ; j < s.size() ; ++ j){
    		while(i < j && uset.find(s[j]) != uset.end())
    			uset.erase(s[i++]);
    		uset.insert(s[j]);
    		ans = max(ans, j - i + 1);
    	}
    	return ans;
    }
};