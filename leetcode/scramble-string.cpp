#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
    	int i, n = s1.size(), m = s2.size(), val1 = 0, val2 = 0;
    	string sl1, sr1, sl2, sr2;
    	if( n != m ) return false;
    	if(s1 == s2) return true;
    	for( i = 0 ; i < n ; ++ i){
    		val1 += s1[i] - '0';
    		val2 += s2[i] - '0';
    	}
    	if(val1 != val2) return false;
    	for(int i = 1; i < n ; ++ i){
    		sl1 = s1.substr(0, i); sr1 = s1.substr(i);
    		sl2 = s2.substr(0, i); sr2 = s2.substr(i);
    		if(isScramble(sl1,sl2) && isScramble(sr1, sr2)) 
    			return true;
    		sl2 = s2.substr(n-i); sr2 = s2.substr(0, n-i);
    		if(isScramble(sl1, sl2) && isScramble(sr1, sr2))
    			return true;
    	}
    	return false;
    }
};

int main(){
	string a, b ; 
	Solution sol;
	cout << sol.isScramble("great", "rgeat") << endl;
	cout << sol.isScramble("rgtae", "great") << endl;
	cout << sol.isScramble("rgtae", "geart") << endl;
	return 0;
}