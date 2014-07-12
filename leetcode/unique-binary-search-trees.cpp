class Solution {
public:
    int numTrees(int n) {
        vector<int> h(n+1);
        h[0] = h[1] = 1 ; 
        for(int i = 2 ; i <= n ; ++ i){
        	h[i] = 0 ; 
        	for(int j = 0; j < i ; ++ j)
        		h[i] += h[j] * h[i-j-1] ;
        } 
        return h[n];
    }
};