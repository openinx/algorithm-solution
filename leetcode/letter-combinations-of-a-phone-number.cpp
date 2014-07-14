#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	void dfs(int depth, string digits, vector<string> &result, char *current, string* maps){
		if(depth >= digits.size() ){
			current[depth] = '\0';
			result.push_back(string(current));
			return;
		}
		int index = digits[depth] - '0';
		for(int i = 0 ; i < maps[index].size(); ++ i){
			current[depth ++ ] = maps[index][i];
			dfs(depth, digits, result, current, maps);
			--depth;
		}
	}
    vector<string> letterCombinations(string digits) {
    	string maps[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    	char *cur = new char[digits.size() + 1];
    	vector<string> result ; 
    	dfs(0 , digits, result, cur, maps);
    	return result;
    }
};

int main(){
	Solution sol ;
	vector<string> result = sol.letterCombinations("23")  ;
	for(int i = 0 ; i < result.size() ; ++ i)
		cout << result[i] << endl;
	//cout << sol.letterCombinations() << endl;
	return 0 ;
}