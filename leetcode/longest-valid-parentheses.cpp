class Solution {
public:
    int longestValidParentheses(string s) {
    	int i, start = 0, ans = 0;
        stack<int> st;
        vector<bool> match(s.size()); 
        fill(match.begin(), match.end(), false);
        for(i = 0 ; i < s.size(); ++ i){
        	if(s[i] == '(')
        		st.push(i);
        	else{
        		if(!st.empty() && s[st.top()] == '('){
        			match[st.top()] = match[i] = true;
        			st.pop();
        		}else{
        			st.push(i);
        		}
        	}
        }
        for(i = 1 ; i < match.size(); ++ i)
        	if(match[i] != match[start]){
        		start = i;
        	}else{
        		if(match[start] == 1)
	        		ans = max(ans, i - start + 1);
        	}
        return ans;
    }
};