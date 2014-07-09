#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<queue>

using namespace std; 


void show(vector< vector<char> > & bd){
	cout << "####################################" << endl ;
	for(int i = 0 ; i < bd.size(); ++ i){
		for(int j = 0 ;j < bd[i].size(); ++ j)
			cout << bd[i][j] << " " ;
		cout << endl ;
	}
}


const int dx[] = {-1,  0, 1, 0};
const int dy[] = { 0, -1, 0, 1};

class Solution {
public:
	void bfs(vector<vector<char> > &board, int x, int y){
		if(board[x][y] != 'O') return ;
		queue< pair<int,int> > que ;
		que.push(pair<int,int>(x,y)); board[x][y] = 'H';
		while(!que.empty()){
			pair<int,int> p = que.front() ; que.pop();
			for(int i = 0 ; i < 4 ; ++ i){
				int cx = p.first + dx[i], cy = p.second + dy[i];
				if(cx >= 0 && cy >= 0 && cx < board.size() && cy < board[0].size() && board[cx][cy] == 'O'){
					que.push(pair<int,int>(cx, cy)) ; board[cx][cy] = 'H';
				}
			}
		}
	}
    void solve(vector<vector<char> > &board) {
    	if(board.size() == 0) return ;
    	queue< pair<int, int> > que ;
    	for(int i = 0 ; i < board.size(); ++ i){
    		if(board[i][0]=='O') bfs(board, i, 0);
    		if(board[i][board[0].size()-1]=='O') bfs(board, i, board[0].size() - 1);
    	}
 	   	for(int i = 0 ; i < board[0].size(); ++ i){
    		if(board[0][i]=='O') bfs(board, 0, i);
    		if(board[board.size()-1][i]=='O') bfs(board, board.size()-1, i);
    	}
    	for(int i = 0 ; i < board.size(); ++ i)
    		for(int j = 0 ; j < board[i].size(); ++ j)
    			if(board[i][j] == 'O')
    				board[i][j] = 'X';
    			else if(board[i][j] == 'H')
    				board[i][j] = 'O';
    }
};

int main(){
	int n ,m ; 
	char c; 
	while(cin >> n >> m ){
		vector< vector<char> > board(n); 
		for(int i = 0 ; i < n ; ++ i){
			board[i] = vector<char>(m);
			for(int j = 0 ; j < m ; ++ j){
				cin >> c; 
				board[i][j] = c ; 
			}
		}
		Solution sol ; 
		sol.solve(board);
		show(board);
	}
	return 0 ;
}