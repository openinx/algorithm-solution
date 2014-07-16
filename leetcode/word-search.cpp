#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool dfs(int x, int y, int index, int n , int m, vector<vector<char> > &board, string word){
		if(index >= word.size()-1) return true;
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1,0,  0};
		bool answer = false;
		for(int i = 0 ; i < 4  && !answer; ++ i){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if(cx >= 0 && cy >= 0 && cx < n && cy < m && board[cx][cy]  == word[index+1]){
				char ch = board[cx][cy];
				board[cx][cy] = '*';
				answer |= dfs(cx, cy, index+1, n, m, board, word);
				board[cx][cy] = ch;

			}
		}
		return answer;
	}
    bool exist(vector<vector<char> > &board, string word) {
    	if(board.size() == 0 || board[0].size() == 0) return false;
    	if(word.size() == 0) return true;
    	int n = board.size(), m = board[0].size(), i , j, answer=false; 
    	for(i = 0 ; i < n && !answer ; ++ i){
    		for(j = 0 ; j < m && !answer; ++ j)
    			if(board[i][j] == word[0]){
    				char ch = board[i][j];
    				board[i][j] = '*';
    				answer |= dfs(i, j, 0, n, m, board, word);
    				board[i][j] = ch;
    			}
    	}
    	return answer;
    }
};

int main(){
	char a[][10] = {
		"ABCE",
		"SFCS",
		"ADEE"
	};
	vector<vector<char> > board;
	Solution sol;
	for(int i = 0 ; i < 4 ; ++ i)
		board.push_back(vector<char>(a[i], a[i] + 4));
	cout << sol.exist(board, "ABCCED") << endl;
	cout << sol.exist(board, "SEE") << endl;
	cout << sol.exist(board, "ABCB") << endl;
	cout << sol.exist(board, "ADEE") << endl;
	cout << sol.exist(board, "SFCS") << endl;
	cout << sol.exist(board, "SFDS") << endl;
	return 0;
}