#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

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
};


int main(){
	Solution sol;
	return 0;
}