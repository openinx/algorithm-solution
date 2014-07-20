#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;


class Solution {
public:

	bool nativeInt(const char *s, int l ,int r){
		if(l > r) return false;
		for(; l <= r ; ++ l)
			if(!isdigit(s[l])) return false;
		return true;
	}

	bool isInt(const char *s, int l, int r){
		if(l > r) return false;
		if(s[l] == '-' || s[l] == '+') ++l;
		if(l > r) return false;
		return nativeInt(s, l , r);
	}

	bool isDecimal(const char *s, int l, int r){
		int i, dot = -1;
		if(l > r) return false;
		if(s[l] == '-' || s[l] == '+') ++l;
		for(i = l ; i <= r ; ++ i) if(s[i] == '-' || s[i] == '+') return false;
		if(l > r) return false;
		for(i = l ; i <= r ; ++ i) if(s[i] == '.') { dot = i ; break; }
		if(dot == -1) return nativeInt(s, l , r);
		if(dot == l) return nativeInt(s, l+1, r);
		if(dot == r) return nativeInt(s, l, r-1);
		return isInt(s, l, dot-1) && isInt(s, dot+1, r);
	}

    bool isNumber(const char *s) {
    	int i , l, r, n = strlen(s), e = -1;
    	l = 0 ; r = n - 1 ;
    	while(l <= r && s[l] == ' ') ++l;
    	while(l <= r && s[r] == ' ') --r;
    	if(l > r ) return false;
    	for(i = l ;i <= r ; ++ i) if(s[i] == 'e') { e = i;  break; }
    	if(e == -1){
    		return isDecimal(s, l, r);
    	}
    	return isDecimal(s, l, e-1) && isInt(s, e+1, r);
    }
};


int main(){
	char s[][100] = { 
				  "0",
				  " -0.1 ",
				  " +0.1 ",
				  " ++0.1 ",
				  "abc",
				  "1 a",
				  "2e10",
				  "2e-10",
				  "2ee-10",
				};
	Solution sol;
	for(int i = 0 ; i < 9 ; ++ i)
		cout << sol.isNumber(s[i]) << endl;
	return 0 ;
}