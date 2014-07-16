#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
	string intToStr(int x){
		if(x == 0) return "0";
		string s = "";
		while(x){
			s.append(1, x%10 + '0');
			x /= 10 ;
		}
		return s;
	}

    string countAndSay(int n) {
    	if(n == 1) return "1";
    	string ans="", s = countAndSay(n-1);
    	int i = 1, start = 0 ; 
    	for(i = 1 ; i < s.size() ; ++ i)
    		if(s[i] != s[start]){
    			ans.append(intToStr(i-start));
    			ans.append(1, s[start]);
    			start = i;
    		}
    	ans.append(intToStr(i-start));
    	ans.append(1, s[start]);
    	return ans;
    }
};


int main(){
	Solution sol;
	for(int i = 1 ; i <= 10; ++ i)
		cout << sol.countAndSay(i) << endl;
	return 0 ;
}