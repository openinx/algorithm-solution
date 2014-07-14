class Solution {
public:
    int romanToInt(string s) {
    	int hash[256], res, i;
    	hash['I'] = 1 ; 
    	hash['V'] = 5 ; 
    	hash['X'] = 10; 
    	hash['L'] = 50 ; 
    	hash['C'] = 100;
    	hash['D'] = 500 ;
    	hash['M'] = 1000;
    	res = hash[s[s.size()-1]];
    	for(i = s.size() -2 ; i >=0 ; --i)
    		if(hash[s[i]] < hash[s[i+1]])
    			res -= hash[s[i]];
    		else
    			res += hash[s[i]];
    	return res;
    }
};