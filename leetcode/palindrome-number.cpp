#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	typedef long long lld;
	lld check(lld x){
		lld base = 1, cnt = 1, y = x, i , j;
		while(y / 10 ){
			y /= 10 ;
			++ cnt;
			base *= 10;
		}
		for(i = 0, j = cnt -1, y = x; i < j ; ++i , -- j){
			if(x % 10 !=  y / base) 
				return false;
			x /= 10;
			y -= (y/base) * base ; 
			base /= 10;
		}
		return true;
	}

    bool isPalindrome(int x) {
        if(x < 0 ) return false;
        if(x < 10) return true;
        return check(x);
    }
};

int main(){
	Solution sol ;
	cout << sol.isPalindrome( 1000 )  << endl;
	cout << sol.isPalindrome( 1 )  << endl;
	cout << sol.isPalindrome( 11 )  << endl;
	cout << sol.isPalindrome( 121 )  << endl;
	cout << sol.isPalindrome( 125 )  << endl;
	cout << sol.isPalindrome( 52125 )  << endl;
	return 0 ;
}