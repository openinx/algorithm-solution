#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if(prices.size() <= 1 )  return 0 ;
    	int result = 0, t ; 
    	for(int i = 1 ; i < prices.size() ; ++ i)
    		result += ((t = prices[i] - prices[i-1]) > 0 ? t: 0 );
    	return result;
    }
};


int main(){
	Solution sol ; 
}
