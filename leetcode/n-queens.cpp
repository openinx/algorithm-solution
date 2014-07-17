#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:

	bool check(vector<int> &x, int depth){
		for(int i = 0 ; i < depth; ++ i)
			if(x[i] == x[depth] || abs(x[i]-x[depth]) == abs(i-depth))
				return false;
		return true;
	}

	void dfs(int depth, int n, vector<int> &x, vector<vector<string> > &results){
		if(depth >= n){
			vector<string> board(n, string(n, '.'));
			for(int i = 0 ; i < n ; ++ i) board[i][ x[i] ] = 'Q';
			results.push_back(board);
			return;
		}
		for(int i = 0 ; i < n ; ++ i){
			x[depth] = i ; 
			if(!check(x, depth)) continue;
			dfs(depth + 1,  n, x , results);
		}
	}

    vector<vector<string> > solveNQueens(int n) {
    	vector<vector<string> > results;
    	vector<int> x(n);
    	dfs(0, n, x, results);
    	return results;
    }
};

int main(){
	int n;
	while(cin >> n){
		Solution sol ;
		vector<vector<string> > results = sol.solveNQueens(n);
		cout << " ******************************************************** " << endl;
		for(int i = 0 ; i < results.size(); ++ i){
			cout << "Solution #" << i+1 << ":" << endl;
			for(int j = 0 ; j < results[i].size(); ++ j){
				cout << results[i][j] << endl;
			}
		}
	}
	return 0;
}