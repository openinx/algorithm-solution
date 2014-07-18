class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	int i , j, last = 1, temp; 
    	vector<int> ans;
    	for(i = digits.size() - 1;  i >= 0 ; --i){
    		temp =  last + digits[i];
    		ans.push_back(temp % 10);
    		last = temp / 10; 
    	}
    	if(last)
    		ans.push_back(last);
    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};