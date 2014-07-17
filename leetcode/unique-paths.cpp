#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
    	int i, j; 
    	vector<int> prev(n), now(n);
    	fill(prev.begin(), prev.end(), 0);
    	for(i = 0 ; i < m; ++ i){
    		now[0] = 1;
    		for(j = 1 ; j < n ; ++ j){
    			now[j] = now[j-1] + prev[j];
    		}
    		for(j = 0 ; j < n ; ++ j) 
    			prev[j] = now[j];
    	}
    	return prev[m-1];
    }
};

int main(){
	Solution sol; 
	cout <<  sol.uniquePaths(1, 2) << endl;
	return 0;
}