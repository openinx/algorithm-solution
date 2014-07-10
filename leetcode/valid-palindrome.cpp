#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
    	int i, j;
    	if(s.size() == 0 )
    		return 1 ; 
    	for(int i = 0 ; i < s.size(); ++ i) 
    		s[i] = ((s[i]>='A' && s[i] <='Z') ? s[i] - 'A' + 'a' : s[i]);
    	i = 0 ; j = s.size() -1;
    	while(i<j){
    		while(i<j && !isalnum(s[i])) ++i;
    		while(i<j && !isalnum(s[j])) --j;
    		if(s[i] != s[j]) return 0;
    		++i; --j;
    	}
    	return 1;
    }
};


int main(){
	Solution sol ; 
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "";
	string s3 = "race a car";
	string s4 = "1a2";
	cout << sol.isPalindrome(s1) << endl ;
	cout << sol.isPalindrome(s2) << endl ;
	cout << sol.isPalindrome(s3) << endl ;
	cout << sol.isPalindrome(s4) << endl ;
	return 0 ;
}