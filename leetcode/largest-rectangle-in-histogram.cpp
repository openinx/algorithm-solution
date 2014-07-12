#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	stack<int> s ; 
    	height.push_back(0);
    	int i = 0, maxArea = 0 ;
    	while( i < height.size() ){
    		if(s.empty() || height[s.top()] <= height[i]){
    			s.push(i++);
    		}else{
    			int t = s.top(); s.pop();
    			maxArea = max(maxArea, height[t] * (s.empty() ? i: i-s.top()-1));
    			cout << "index: " << t << "  maxArea: " << maxArea << endl; 
    		}
    	}
    	return maxArea;
    }
};

int main(){
	Solution sol ; 
	int h[] = {2, 1, 5, 6, 2, 3 };
	vector<int> height(h, h+5); 
	cout << sol.largestRectangleArea(height) << endl ;
	return 0;
}