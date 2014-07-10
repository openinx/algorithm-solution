#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
    	if(prices.size() <= 1) return 0 ;
    	int i, minval, maxval, answer = 0;
    	vector<int> forward(prices.size()), backward(prices.size()); 
    	//compute forward 
    	for(forward[0]= 0, i = 1 , minval = prices[0]; i < prices.size() ; ++ i){
    		forward[i] = max(forward[i-1], prices[i] - minval);
    		minval = min(prices[i], minval);
    	}
    	backward[prices.size() - 1] = 0;
    	maxval = prices[prices.size()-1];
    	for(i = prices.size()-2 ; i >= 0; --i){
    		backward[i] = max(backward[i+1], maxval - prices[i]);
    		maxval = max(prices[i], maxval);
    	}
    	for(int i = 0 ; i < prices.size() ; ++ i){
    		answer = max(answer, forward[i]);
    		answer = max(answer, backward[i]);
    	}
    	for(int i = 1 ; i < prices.size()-1; ++ i){
    		answer = max(answer, forward[i] + backward[i+1]);
    	}
    	return answer;
    }
};

int main(){
	int a[] = {3, 2, 1 , 5 , 2 , 6 };
	vector<int> prices(a, a + sizeof(a) / sizeof(int));
	Solution sol ;
	cout << sol.maxProfit(prices) << endl ;
	return 0 ;
}