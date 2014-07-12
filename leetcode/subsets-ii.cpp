#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:

	typedef map<int,int>::iterator uit ;

	void dfs(int *val, int *cnt, int now, int size, vector< vector<int> > &result){
		if( now == size){
			vector<int> v ; 
			for(int i = 0 ; i < size ; ++ i){
				for(int j = 0 ; j < cnt[i]; ++ j) v.push_back(val[i]);
			}
			result.push_back(v);
			return;
		}
		int t = cnt[now];
		for(int i = 0 ; i <= t ; ++ i){
			cnt[now] = i ; 
			dfs(val, cnt, now+1, size, result);
		}
		cnt[now] = t ; 
	}

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        map<int, int> valMap; 
        vector<vector<int> > result ;
        for(int i = 0 ; i < S.size() ; ++ i) 
        	++valMap[S[i]] ;
        int idx = 0 ; 
        int *val = new int[valMap.size()] ; 
        int *cnt = new int[valMap.size()] ; 
        for(map<int,int>::iterator it = valMap.begin(); it!=valMap.end(); ++it){
        	val[idx] = it->first ; 
        	cnt[idx] = it->second; 
        	idx++ ;
        }
        dfs(val,cnt,0, idx, result);
        delete val ; 
        delete cnt ; 
        return result; 
    }
};

int main(){
	Solution sol ; 
	int a[] = {1, 2, 2} ; 
	vector<int> v(a, a + 3);
	vector< vector<int> > result =  sol.subsetsWithDup(v);
	for(int i = 0 ; i < result.size() ; ++ i){
		cout << "[ " ; 
		for(int k = 0 ; k < result[i].size(); ++ k)
			cout << "  " << result[i][k] ; 
		cout << "  ]"  << endl ;; 
	}
	return 0;
}