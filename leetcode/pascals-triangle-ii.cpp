class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res, prev;
    	prev.push_back(1); 
    	if(rowIndex < 1)  return prev;
    	res.push_back(1); 
    	for(int k = 1 ; k <= rowIndex ; ++k ){
    		for(int i = 1 ; i < k ; ++ i){
    			res[i] = prev[i] + prev[i-1];
    		}
    		res.push_back(1); 
    		prev.clear();
    		for(int i = 0 ; i < res.size(); ++i)
    			prev.push_back(res[i]) ;
    	}
    	return res; 
    }
};