#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;

#define unordered_map map
#define unordered_set set


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	unordered_map<string, int>  umap;
    	vector<string> result;
    	for(int i = 0 ; i < strs.size(); ++ i){
    		string s= strs[i];
    		sort(s.begin(), s.end());
    		umap[ s ] ++ ;
    	}
    	for(int i = 0 ; i < strs.size(); ++ i){
    		string s = strs[i];
    		sort(s.begin(), s.end());
    		if(umap[s] > 1){
    			result.push_back(strs[i]);
    		}
    	}
    	return result;
    }
};

int main(){
	Solution sol;
	string a[] = {"foo", "oof", "bar", "arb", "far", "fds", "ofo"};
	vector<string> strs(a, a + sizeof(a) / sizeof(string));
	vector<string> result = sol.anagrams(strs);
	for(int i = 0 ; i < result.size(); ++ i){
		cout << result[i] << endl;
	}
	return 0;
}