#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	string s = path;
    	int i = 0, k, len = s.size();
    	vector<string> stack;
    	stack.push_back("/");
    	while(i < len && s[i] != '/') ++i;
    	while(i < len){
    		if(s[i] == '/'){
    			++i;
    			if(!stack.empty() && stack.back() == "/") continue;
    			stack.push_back("/");
    		}else if(s[i] == '.'){
    			if(i + 1 < len && s[i + 1] == '.'){
    				if(i + 2 < len && s[i + 2] != '/'){
    					// three dots.
    					for(k = i ; k < len && s[k]!='/'; ++ k);
    					stack.push_back(path.substr(i, k - i));
    					i = k ;
    				}else{
    					// two dots.
    					if(stack.size() > 1 && stack.back() == "/") stack.pop_back();
    					if(stack.size() > 1 && stack.back() != "/") stack.pop_back();
    					i += 2;
    				}
    			}else if(i + 1 < len && s[i + 1 ] != '/'){
    				for(k = i ; k < len && s[k] != '/'; ++ k);
    				stack.push_back(path.substr(i, k - i ));
    				i = k;
    			}else{
    				++i;
    			}
    		}else{
    			for(k = i; k < len && s[k] != '/' && s[k] != '.'; ++ k);
    			stack.push_back(path.substr(i, k-i));
    			i = k ;
    		}
    	}
    	if(stack.size() > 1 && stack.back() == "/") stack.pop_back();
    	string ans = "";
    	for(int i = 0 ;i < stack.size(); ++ i)
    		ans.append(stack[i]);
    	return ans;
    }
};

int main(){
	Solution sol;
	cout << "************************" << endl;
	cout << sol.simplifyPath("/home/") << endl;
	cout << sol.simplifyPath("/...") << endl;
	cout << sol.simplifyPath("/.") << endl;
	cout << sol.simplifyPath("/.//aab/../") << endl;
	cout << sol.simplifyPath("/../") << endl;
	cout << sol.simplifyPath("/home/../foo/") << endl;
	cout << sol.simplifyPath("/..hidden") << endl;
	cout << sol.simplifyPath("/.hidden") << endl;
	return 0;
}