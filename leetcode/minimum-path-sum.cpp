class Solution {
public:
	#define _min(x,y) ( (x)==-1 ? (y):( ((x)==-1) ? (y): min(x,y)) )
    int minPathSum(vector<vector<int> > &grid) {
    	if(grid.size() == 0 ) return 0;
    	int n = grid.size(), m = grid[0].size(), i, j;
    	vector<int> now(m), prev(m);
    	fill(prev.begin(), prev.end(), -1);
    	prev[0] = 0;
    	for(i = 0 ; i < n ; ++ i){
    		now[0] = prev[0] + grid[i][0] ;
    		for(j = 1 ; j < m ; ++ j){
    			now[j] = -1;
    			if(prev[j] != -1)
    				now[j] = _min(now[j], prev[j] + grid[i][j]);
    			if(now[j-1] != -1)
    				now[j] = _min(now[j], now[j-1] + grid[i][j]);
    		}
    		for(j = 0 ; j < m; ++ j)
    			prev[j] = now[j];
    	}
    	return prev[m-1];
    }
};