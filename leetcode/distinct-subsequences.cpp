class Solution {
public:
    int numDistinct(string S, string T) {
    	vector<int> now(T.size()+1), prev(T.size()+1);
    	fill(prev.begin(), prev.end(), 0);
    	prev[0] = 1 ; 
    	for(int i = 1 ; i <= S.size() ; ++ i){
    		now[0] = 1; 
    		for(int j = 1; j <= T.size() ; ++ j){
    			now[j] = (S[i-1] == T[j-1] ? prev[j-1] + prev[j]: prev[j]) ;
    		}
    		for(int j = 0 ; j <= T.size() ; ++ j) 
    			prev[j] = now[j];
    	}
    	return now[T.size()];
    }
};
