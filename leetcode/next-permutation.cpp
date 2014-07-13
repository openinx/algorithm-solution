class Solution {
public:
	typedef multiset<int>::iterator msit;
    void nextPermutation(vector<int> &num) {
    	int now, i , k;
    	multiset<int> iset;
    	for(i = num.size()-1; i>=0; --i){
    		msit it = iset.upper_bound(num[i]);
    		if(it != iset.end()){
    			now = *it ;
    			iset.erase(it);
    			iset.insert(num[i]);
    			num[i] = now;
    			k = i;
    			for(msit it = iset.begin(); it!=iset.end(); it++)
    				num[++k] = *it;
    			return;
    		}
    		iset.insert(num[i]);
    	}
    	k = 0 ;
    	for(msit it = iset.begin(); it!=iset.end(); it++){
    		num[k++] = *it;
    	}
    }
};
