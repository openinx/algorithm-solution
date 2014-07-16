#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <string>

using namespace std;


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

    vector<vector<int> > permute(vector<int> &num) {
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

int main(){
	int n , x; 
	while( cin >> n){
		vector<int> num;
		for(int i = 0 ; i < n; ++ i){
			cin >> x;
			num.push_back(x);
		}
		Solution sol;
		vector<vector<int> > result = sol.permute(num);
		cout << " *************** Solution ***************** " << endl;
		for(int j = 0 ; j < result.size(); ++ j){
			cout << "####: ";
			for(int k = 0 ; k < result[j].size(); ++ k){
				cout << " " << result[j][k] ; 
			}
			cout << endl;
		}
	}
	return 0;
}