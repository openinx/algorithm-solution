#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

#define unordered_map map
#define unordered_set set

using namespace std;

class Solution {
public:
	typedef set<int>::iterator usit;
	void dfs(vector<int> &num, vector<int> &cur, int depth, int curVal,
			 int target, vector< vector<int> > &result){
		if(depth  >= num.size()){
			if(curVal == target){
				vector<int> ans(cur.begin(), cur.end());
				result.push_back(ans);
			}
			return;
		}
		int i , cnt = 0 ;
		for(i = 0 ; curVal + num[depth] * i <= target; ++i){
			if(curVal + num[depth] * i < target && curVal + num[depth] * (i+1) > target)
				continue;
			dfs(num, cur, depth + 1, curVal + num[depth] * i, target, result);
			cur.push_back(num[depth]);
			cnt ++ ;
		}
		while(cnt -- ) cur.pop_back();
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    	vector<vector<int> > result;
    	vector<int> num, cur;
    	set<int> uiset(candidates.begin(), candidates.end());
    	for(usit it = uiset.begin(); it != uiset.end(); ++it)
    		num.push_back(*it);
    	dfs(num, cur, 0, 0, target, result);
    	return result;
    }
};


int main(){
	int n , x , target; 
	while(cin >> n >> target){
		vector<int> candidates ;
		for(int i = 0 ;i < n ; ++ i){
			cin >> x; 
			candidates.push_back(x);
		}
		Solution sol;
		vector< vector<int> > result = sol.combinationSum(candidates, target);
		for(int i =  0 ; i < result.size(); ++ i){
			cout << "[" ; 
			for(int j = 0 ; j < result[i].size() ; ++ j)
				cout << " " << result[i][j];
			cout << "]" << endl;
		}
	}
	return 0 ;
}