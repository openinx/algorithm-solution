#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if(prices.size() == 0 ) return 0 ;
    	int minval  = prices[0] , i, result = 0; 
    	for( i = 1 ; i < prices.size() ; ++ i){
    		result = max( result, prices[i] - minval ) ;
    		minval = min( minval, prices[i]);
    	}
    	return result;
    }
};
	
int main(){
	vector<int> prices ; 
	int a[] = {3, 2 , 1 , 5, 2, 6};
	for(int i = 0 ; i < sizeof(a) / sizeof(int) ; ++ i)
		prices.push_back(a[i]);
	Solution sol ; 
	cout << sol.maxProfit( prices ) << endl ;
}