#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define unordered_set  set
#define unordered_map  map

void show(vector<vector<int> > &graph){
	for(int i = 1 ; i< graph.size() ; ++ i){
		cout << "#### " << i << " :";
		for(int j = 0 ; j < graph[i].size(); ++ j)
			cout <<  " "  << graph[i][j]  ;
		cout << endl;
	}
}

typedef unordered_set<string>::iterator sit;
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
    	int cnt = 0 ;
    	unordered_map<string, int> index;
    	dict.insert(start);
    	dict.insert(end);
    	for(sit it = dict.begin(); it!=dict.end(); ++it){
    		index[*it] = cnt++; 
    	}
    	vector<vector<int> > graph(cnt);
    	string sa , sb ;
    	for(sit it = dict.begin(); it!=dict.end(); ++it){
    		sa = *it;
    		int a = index[sa];
    		for(int i = 0 ; i < sa.size(); ++ i){
    			for(int k = 'a'; k <='z'; ++ k){
    				char ch = sa[i]; 
    				sa[i] = k ; 
    				int b = index[sa];
    				if(b && a != b && dict.find(sa) != dict.end()){
    					graph[a].push_back(b);
    				}
    				sa[i] = ch ; 
    			}
    		}
    	}
    	queue<int> q ; 
    	int a = index[start], b = index[end], c, d;
    	vector<int> visited;
    	for(int i = 0; i < cnt ; ++ i) 
    		visited.push_back(-1);
    	q.push(a); 
    	visited[a] = 0;
    	while(!q.empty()){
    		c = q.front(); q.pop();
    		for(int i = 0 ; i < graph[c].size(); ++ i){
    			d = graph[c][i];
    			if(d == b)
    				return visited[c]+ 1 ;
    			if(visited[d] != -1) 
    				continue;
    			visited[d] = visited[c] + 1 ;
    			q.push(d);
    		}
    	}
        return visited[b];
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
		cout << "##### : " << sol.ladderLength(start, end, dict) << endl;
	}
	return 0 ;
}