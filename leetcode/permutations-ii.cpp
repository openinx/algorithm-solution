class Solution {
public:

	void dfs(int depth, int maxDepth, vector<int> &uniq, vector<int> &cnt, vector<int> &current, vector< vector<int> > &result){
		if(depth >= maxDepth){
			result.push_back(vector<int>(current.begin(), current.end()));
			return;
		}
		for(int i = 0 ; i < uniq.size() ; ++ i)
			if(cnt[i]){
				--cnt[i];
				current.push_back(uniq[i]);
				dfs(depth + 1, maxDepth, uniq, cnt, current, result);
				current.pop_back();
				++cnt[i];
			}
	}

    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<int> uniq, cnt, current;
    	map<int,int> imap;
    	vector<vector<int> > result;
    	for(int i = 0 ; i < num.size(); ++ i)
    		imap[ num[i] ] ++ ;
    	for(map<int,int>::iterator it = imap.begin(); it!=imap.end(); ++it){
    		uniq.push_back(it->first);
    		cnt.push_back(it->second);
    	}
    	dfs(0, num.size(), uniq, cnt, current, result);
    	return result;
    }
};