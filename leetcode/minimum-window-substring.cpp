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
        int i, n , m , l, r, curlen, len,  start;
        int need[256] = {0}, cur[256] = {0}; 
        n = S.size(); m = T.size();
        for(i = 0 ; i < m; ++ i)
            need[T[i]] ++ ;
        len = n + 1 ;  start = 0;
        for(curlen = l = r = 0 ; r < n ; ++ r){
            if(need[ S[r] ] == 0 ) continue;
            if( ++ cur[ S[r] ] <= need[ S[r] ]) 
                ++ curlen;
            if(curlen == m){
                while( need[ S[l] ] == 0 || cur[ S[l] ] > need[ S[l] ]) {
                    if( cur[ S[l] ] > need[ S[l] ]) --cur[ S[l] ];
                    ++ l;
                }
                if( r - l + 1 < len){
                    len = r - l + 1;
                    start = l ;
                }
            }
        }
        return len == n + 1 ? "" : S.substr(start, len);
    }
};

int main(){
	Solution sol;
	cout << sol.minWindow("a", "a") << endl;
	cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("acbbaca", "aba") << endl;
	return 0;
}