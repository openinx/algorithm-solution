#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
    	if(matrix.size() == 0 ) return 0 ;
    	int n = matrix.size(), m = matrix[0].size();
    	int *prev = new int[m+1], *now = new int[m+1], i , j, maxArea = 0;
    	fill(prev, prev + m , 0 );
    	for(i = 0 ; i < n;  ++ i){
    		for(j = 0 ; j < m ; ++ j){
    			now[j] = (matrix[i][j] == '0' ? 0: prev[j] + 1); 
    		}
    		maxArea = max(maxArea, largestRectangleArea(now, m));
    		for(j = 0 ; j < m ; ++ j) 
    			prev[j] = now[j];
    	}
    	return maxArea;
    }
    int largestRectangleArea(int height[], int hsize) {
    	stack<int> s ; 
    	height[hsize++] = 0;
    	int i = 0, maxArea = 0 ;
    	while( i < hsize){
    		if(s.empty() || height[s.top()] <= height[i]){
    			s.push(i++);
    		}else{
    			int t = s.top(); s.pop();
    			maxArea = max(maxArea, height[t] * (s.empty() ? i: i-s.top()-1));
    		}
    	}
    	return maxArea;
    }
};

int main(){
	Solution sol ; 
	char a[][6] = {
		"01100", 
		"00011", 
		"00000", 
		"10000",
	};
	vector< vector<char> > matrix;
	for(int i = 0 ; i < 4 ; ++ i)
		matrix.push_back(vector<char>(a[i], a[i] + 5));
	cout << sol.maximalRectangle(matrix) << endl; 
	return 0;
}