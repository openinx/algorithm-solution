#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stdio.h>
#include <vector>

#define unordered_map map
#define unordered_set set

using namespace std;


class Solution {
public:
    string minWindow(string S, string T) {
    	int anslen = S.size() + 1 , start, end, i = 0, j = 0 , curlen = 0; 
    	unordered_map<char, int> tm , dict ; 
    	for(i = 0 ; i < T.size(); ++ i) tm[ T[i] ] ++ ;
    	for(i = 0 ; i < S.size(); ++ i){
    		if( tm[ S[i] ] == 0 ) continue;
    		while( j < i && ( dict[ S[i] ] >= tm[ S[i] ] || tm[ S[j] ] == 0)) { 
    			j ++ ; 
    			curlen -- ; 
    			if( dict[ S[j] ] > 0 ) dict[ S[j] ] -- ;
    		}
    		dict[ S[i] ] ++ ; 
    		curlen ++; 
    		if(curlen >= T.size()){
    			if( anslen > (i - j + 1)){
	    			anslen = i - j + 1;
    				start = j ; 
    				end = i ; 
    			}
    		}
    	}
    	cout << "answer length:" << anslen << " start:" << start << " end:" << end << endl;
    	return anslen != S.size() + 1 ? S.substr(start, end - start + 1): "";
    }
};

int main(){
	Solution sol;
	cout << sol.minWindow("a", "a") << endl;
	cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
	return 0;
}