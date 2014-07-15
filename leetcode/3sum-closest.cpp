#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    	int i , j , k , c , sum = 1<<28, trip ; 
    	sort(num.begin(), num.end());
    	for(i = 0 ;i < num.size(); ++ i){
    		j = 0 ; 
    		k = i - 1;
    		while(j < k){
    			trip = num[j] + num[k] + num[i];
    			if(j < k && trip > target){
    				--k;
    			}else if(j < k && trip < target){
    				++j;
    			}else if(trip == target)
    				return target;
    			if(abs(trip - target) < abs(sum - target)){
                    sum = trip;
                }
    		}
    	}
    	return sum;
    }
};

int main(){
	Solution sol;
	//int a[] = {-1, 2, 1 , -4};
    int a[] = {0, 2, 1, -3};
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	cout << sol.threeSumClosest(v, 1) << endl;
	return 0;
}