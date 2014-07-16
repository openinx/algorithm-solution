#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
    	bool visited[10];
    	memset(visited, 0, sizeof(visited));
    	int i, j, x, y, index;
    	for(i = 0 ; i < 3 ; ++ i)
    		for(j = 0 ; j < 3 ; ++ j){
    			memset(visited, 0, sizeof(visited));
    			for(x = 0 ; x < 3 ; ++ x)
    				for(y = 0 ; y < 3 ; ++ y)
    					if(board[3*i+x][3*j+y] != '.'){
    						index = board[3*i+x][3*j+y] - '0';
    						if(visited[index]) 
    							return false;
    						visited[index] = true;
    					}
    		}
    	for(i = 0 ; i < 9 ; ++ i){
    		memset(visited, 0 ,sizeof(visited));
    		for(j = 0 ; j < 9 ; ++ j){
    			if(board[i][j] != '.'){
    				index = board[i][j] - '0';
    				if(visited[index]) 
    					return false;
    				visited[index] = true;
    			}
    		}
    	}
    	for(j = 0 ; j < 9 ; ++ j){
    		memset(visited, 0, sizeof(visited));
    		for(i = 0 ; i < 9 ; ++ i){
    			if(board[i][j] != '.'){
    				index = board[i][j] - '0';
    				if(visited[index])
    					return false;
    				visited[index] = true;
    			}
    		}
    	}
    	return true;
    }

	bool dfs(int depth, vector< vector<char> > &board){
		if(depth >= 9 * 9 ){
			return true;
		}
		int x = depth / 9 , y = depth % 9 ; 
		if(board[x][y] != '.') return dfs(depth+1, board);
		for(char i = '1' ; i <= '9' ; ++ i){
			board[x][y] = i ;  
			if(isValidSudoku(board)){
				if(dfs(depth + 1, board))
					return true;
			}
		}
		board[x][y] = '.';
		return false;
	}

    void solveSudoku(vector<vector<char> > &board) {
    	dfs(0, board);
    }
};

int main(){
	char a[][10] = {
		"53..7.9..",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4.68.37.1",
		"7...2...6",
		".61...28.",
		"...419..5",
		"3.5.8..79"
	};
	vector< vector<char> > board;
	int i , j; 
	for(int i = 0 ; i < 9 ; ++ i){
		vector<char> v(a[i] , a[i] + 9);
		board.push_back(v);
	}
	Solution sol;
	sol.solveSudoku(board);
	cout << "Solution:" << endl;
	for(int i = 0 ; i< board.size(); ++ i){
		for(int j = 0 ; j < board[i].size(); ++ j)
			cout << " " <<  board[i][j];
		cout << endl;
	}
	return 0;
}