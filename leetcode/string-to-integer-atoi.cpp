#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
	typedef long long lld;
    int atoi(const char *str) {
    	int len = strlen(str), i = 0; 
    	while(str[i] == ' ') ++i; 
    	if(str[i] == '\0' || (str[i] != '-' && str[i] != '+' && !isdigit(str[i]))) return 0; 
    	int negative = 0; 
    	long long res = 0;
    	if(str[i] == '-') {
    		negative = 1 ; ++i ;
    	}else if(str[i] == '+') {
    		negative = 0 ; ++i;
    	}
    	if(!isdigit(str[i])) return 0;
    	while(isdigit(str[i])) {
    		res = res * 10 +  (str[i]- '0');
    		++i;
    		if(negative && res >= (lld)2147483648)
	    			return -2147483648;
	    	if(!negative && res >= (lld)2147483647)
		    		return 2147483647;
    	}
    	cout << " #### " << endl;
    	if(negative){
    		if(res >= (lld)2147483648)
    			return -2147483648;
    		return -res ;
    	}else{
    		if(res >= (lld)2147483647)
    			return 2147483647;
    		return res ;
    	}
    }
};

int main(){
	Solution sol;
	cout << sol.atoi("-2147483647") << endl;
	cout << sol.atoi("    +1###") << endl;
	cout << sol.atoi("    +2###") << endl;
	cout << sol.atoi("    -2341341#####") << endl;
	cout << sol.atoi("    -234134123423443#####") << endl;
	cout << sol.atoi("    -2341341234234433333333333333333333333333333333333333333333333333#####") << endl;
	return 0;
}