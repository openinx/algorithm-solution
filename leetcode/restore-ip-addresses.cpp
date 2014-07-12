#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	bool ok(string a){
		int res = 0;
		if(a.size() == 0 || ((a.size() > 1) && a[0] == '0'))
			return false;
		for(int i = 0 ; i < a.size(); ++ i){
			res = res * 10 + a[i] - '0';
			if(res > 255) return false;
		}
		return true
	}
    vector<string> restoreIpAddresses(string s) {
    	vector<string> result ;
    	if(s.size() > 12 ) return result;
    	for(int i = 0; i < s.size() ; ++ i){
    		for(int j = i+1; j < s.size(); ++j)
    			for(int k=j+1; k< s.size()-1; ++ k){
    				string a = s.substr(0, i+1);
    				string b = s.substr(i+1, j-i);
    				string c = s.substr(j+1, k-j);
    				string d = s.substr(k+1, s.size()-1-k);
    				if(ok(a) && ok(b) && ok(c) && ok(d))
    					result.push_back(a + "." + b + "." + c + "." + d);
    			}
    	}
    	return result;
    }
};

int main(){
	Solution sol ; 
	string s = "25525511135";
	vector<string> v = sol.restoreIpAddresses(s);
	for(int i = 0 ; i < v.size() ; ++ i)
		cout << v[i] << endl ;
	return 0 ;
}