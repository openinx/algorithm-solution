class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	int i = strlen(s)-1, ans = 0;
    	while(i>=0 && s[i]==' ') --i;
    	while(i>=0 && s[i]!=' ') --i, ++ans;
    	return ans;
    }
};