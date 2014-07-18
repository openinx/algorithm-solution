class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	if(obstacleGrid.size() == 0) return 0;
    	int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    	vector<int> prev(m), now(m);
    	fill(prev.begin(), prev.end(), 0);
    	prev[0] = 1;
    	for(int i = 0 ; i < n ; ++ i){
    		now[0] = obstacleGrid[i][0] == 1 ? 0: prev[0];
    		for(int j = 1 ; j < m ; ++ j){
    			now[j] = 0;
    			if(obstacleGrid[i][j] != 1){
    				now[j] += prev[j];
    				now[j] += now[j-1];
    			}
    		}
    		for(int j = 0 ; j < m ; ++ j) prev[j] = now[j];
    	}
    	return prev[m-1];
    }
};