class Solution {
public:
	void dfs(int depth, vector<int> &s , vector<int> &current, vector<vector<int> > &result){
		if(depth == s.size()){
			result.push_back(vector<int>(current.begin(), current.end()));
			return;
		}
		dfs(depth + 1, s, current, result);
		current.push_back(s[depth]);
		dfs(depth + 1, s, current, result);
		current.pop_back();
	}

    vector<vector<int> > subsets(vector<int> &S) {
    	vector<int> current;
    	vector<vector<int> > result;
    	sort(S.begin(),S.end());
    	dfs(0, S, current, result);
    	return result;
    }
};