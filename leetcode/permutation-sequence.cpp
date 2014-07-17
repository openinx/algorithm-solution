class Solution {
public:
    string getPermutation(int n, int k) {
    	string ans;
    	vector<int> used(n), perm(n);
    	perm[0] = 1;
    	for(int i = 1 ; i < n; ++ i) perm[i] = perm[i-1] * i ;
    	fill(used.begin(), used.end(), 0);
    	for(int i = 0 ; i < n; ++ i){
    		for(int j = 0 ; j < n; ++ j)
    			if(used[j] == 0){
    				if(k > perm[n-i-1]){
    					k -= perm[n-i-1];
    				}else{
    					used[j] = 1;
    					ans.append(1, j + '1');
    				}
    			}
    	}
    	return ans;
    }
};