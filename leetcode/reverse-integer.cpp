class Solution {
public:
    int reverse(int x) {
    	long long res = 0 , flag = 1;
    	if(x < 0 ){
    		x = -x ; flag = -1;
    	} 
    	while(x){
    		res =  res * 10 + (x%10);
    		x /= 10 ;
    	}
    	return flag == -1 ? -res: res;
    }
};