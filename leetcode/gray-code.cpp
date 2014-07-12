class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> v ; 
    	if(n == 0 ){
    		v.push_back(0);
    	}else if(n == 1) {
    		v.push_back(0); v.push_back(1);
    	}else{
    		vector<int> w = grayCode(n-1);
    		for(int i =0 ; i< w.size(); ++ i) 
    			v.push_back(w[i]) ;
    		for(int i = w.size()-1; i>=0 ; --i)
    			v.push_back( (1<<(n-1)) | w[i]);
    	}
    	return v;
    }
};
