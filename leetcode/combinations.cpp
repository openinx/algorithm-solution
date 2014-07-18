#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	void dfs(int dep, int k , vector<int> &used, vector<int> &ans, vector<vector<int> > &result){
		if(dep >= k){
			result.push_back(ans);
			return;
		}
		for(int i = (ans.size() ? ans.back(): 0) ; i < used.size(); ++ i)
			if(used[i] == false){
				used[i] = true; ans.push_back(i+1);
				dfs(dep+1, k, used, ans, result);
				ans.pop_back(); used[i] = false;
			}
	}

    vector<vector<int> > combine(int n, int k) {
    	vector<int> used(n, 0), ans;
    	vector<vector<int> >  result;
    	dfs(0, k, used, ans, result);
    	return result;
    }
};

int main(){
	int n , k ; 
	while(cin >> n >> k){
		Solution sol;
		vector< vector<int> > result = sol.combine(n , k );
		for(int i = 0 ; i < result.size(); ++ i){
			cout << "###: " ; 
			for(int j = 0 ; j < result[i].size(); ++ j)
				cout << " " << result[i][j] ; 
			cout << endl;
		}
	}
	return 0;
}