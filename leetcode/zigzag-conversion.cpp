#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	string ans;
    	if( nRows == 1) return s ;
    	int n = s.size();
    	int mod = 2 * nRows - 2, k = n / mod , i , j , index, t;
    	if( n % mod != 0 )  ++ k;
    	for(i = 0 ; i < nRows; ++ i){
    		for(j = 0 ; j < k; ++ j){
    			index = j * mod + i ;
    			if(index >= s.size() ) continue ;
    			ans.push_back(s[index]);
    			index = j * mod + nRows + nRows - 2 - i;
    			if(i == 0 || i == nRows - 1 || index >= s.size() ) continue ; 
    			ans.push_back(s[index]);
    		}
    	}
    	return ans;
    }
};

int main(){
	Solution sol ;
	cout << sol.convert("PAYPALISHIRING", 3) << endl;
	return 0;
}