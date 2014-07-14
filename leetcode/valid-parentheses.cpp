class Solution {
public:
    bool isValid(string s) {
        stack<int> st ; 
        for(int i = 0 ; i < s.size(); ++ i){
        	switch(s[i]){
	        	case ')':
					if(st.empty() || st.top() != '(')
						st.push(s[i]);
					else
						st.pop();
					break;
				case '(':
					st.push(s[i]);
					break;
				case ']':
					if(st.empty() || st.top() != '[')
						st.push(s[i])
					else
						st.pop()
					break;
				case '[':
					st.push(s[i])
					break;
				case '{':
					st.push(s[i])
					break;
				case '}':
					if(st.empty() || st.top() != '{')
						st.push(s[i])
					else
						st.pop()
					break;
				default:
					st.push(s[i])
					break;
			}
        }
        return st.empty();
    }
};