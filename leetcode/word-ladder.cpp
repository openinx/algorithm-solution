#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <queue>
#include <map>
#include <set>

#define unordered_map map
#define unordered_set set 

using namespace std;

class Solution {
public:
	typedef unordered_set<int>::iterator uit ;
	void backtrace( int start, 
				    int end , 
					unordered_map<int,string> &reverse_index,
					vector< unordered_set<int> > &reached, 
					vector< vector<string> > &result, 
					vector<int> &current){
		if(start == end) {
			vector<string> ans ;
			for(int i = current.size() -1 ; i >=0 ; --i){
				ans.push_back(reverse_index[current[i]]);
			}
			result.push_back(ans);
		}else{
			for(uit it=reached[end].begin(); it!=reached[end].end(); ++it){
				current.push_back(*it);
				backtrace(start, *it, reverse_index, reached, result, current);
				current.pop_back();
			}
		}
	}

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    	int cnt  = 0;
    	unordered_map<string, int> index;
    	unordered_map<int, string> reverse_index;
    	dict.insert(start);
    	dict.insert(end);
    	for(unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); ++it){
    		index[*it] = cnt ;
    		reverse_index[cnt++] = *it ;
    	}
    	//bfs
    	vector<int> visited(cnt, 0);
    	vector< unordered_set<int> > reached(cnt); 
    	int start_idx = index[start], end_idx = index[end];
    	queue<int> q ;
    	q.push(start_idx) ;
    	visited[start_idx] = 1;  
    	reached[start_idx] = unordered_set<int>();
    	while(!q.empty()){
    		int from = q.front() ; q.pop(); 
    		string s = reverse_index[from];
    		for(int i = 0 ;i < s.size() ; ++ i){
    			for(int k = 'a'; k <='z' ; ++ k){
    				string d = s ; 
    				d[i] = k; 
    				if(dict.find(d) == dict.end()) 
    					continue;
    				int to = index[d];
    				if(visited[to] != 0){
    					if(visited[to] == visited[from] + 1){
    						reached[to].insert(from);
    					}
    					continue;
    				}
    				visited[to] = visited[from] + 1 ;
    				reached[to] = unordered_set<int>();
    				reached[to].insert(from);
    				q.push(to);
    			}
    		}
    	}
    	//cout << "#######: " << visited[end_idx] << endl ;
    	vector< int > current; 
    	vector< vector<string> > result ; 
    	current.push_back(end_idx);
    	backtrace(start_idx, end_idx, reverse_index, reached, result, current);
    	return  result;
    }
};

int main(){
	Solution sol ; 
	int n ; 
	string start, end; 
	unordered_set<string> dict;
	while(cin >> n >> start >> end ){
		for(int i = 0 ; i < n; ++ i){
			string s ; 
			cin >> s ; 
			dict.insert(s);
		}
		//cout << "##### : " << sol.findLadders(start, end, dict) << endl;
		vector<vector<string> > results = sol.findLadders(start, end, dict);
		cout << "[" <<  endl ;
		for(int i = 0 ;i < results.size() ; ++ i){
			for(int j = 0 ; j < results[i].size(); ++ j){
				cout <<  " " << results[i][j] ; 
			}
			cout << endl ;
		}
		cout << "]" << endl ;
	}
	return 0 ;
}