#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
	void dfs(vector<int> &num, vector<int> &cur,
			 int depth, int curVal, int target,
			 vector< vector<int> > & result){
		if(depth >= num.size()){
			if(curVal == target){
				result.push_back(vector<int>(cur.begin(), cur.end()));
			}
			return;
		}
		curVal += num[depth];
		if(curVal <= target && !(curVal < target && curVal + num[depth] > target)){
			cur.push_back(num[depth]);
			dfs(num, cur, depth+1, curVal, target, result);
			cur.pop_back();
		}
		curVal -= num[depth];
		int k;
		for(k = depth + 1 ; k < num.size() && num[k] == num[depth]; ++ k);
		if(curVal <= target && !(curVal < target && curVal + num[depth] > target)){
			dfs(num, cur, k, curVal, target, result);
		}
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    	vector< vector<int> > result;
    	vector<int> cur ; 
    	sort(num.begin(), num.end());
    	dfs(num, cur, 0, 0, target, result);
    	return result;
    }
};


int main(){
	int n ,target, x ;
	while(cin >> n >> target){
		vector<int> num;
		for(int i = 0 ; i < n ; ++ i){
			cin >> x ; 
			num.push_back(x);
		}
		Solution sol;
		cout << "Solution:" << endl;
		vector<vector<int> > result = sol.combinationSum2(num, target);
		for(int i = 0 ; i < result.size() ; ++ i){
			cout << "[";
			for(int j = 0 ; j < result[i].size(); ++ j){
				cout << " " << result[i][j];
			}
			cout << "]" << endl;
		}
	}
	return 0;
}