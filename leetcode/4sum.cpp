#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	int i, j, l , r, sum; 
    	vector< vector<int> > result;
    	sort(num.begin(), num.end());
    	for(i = 0 ; i < num.size(); ++ i){
    		if(i > 0 && num[i] == num[i-1])
    			continue;
    		for(j = i + 1 ; j < num.size(); ++ j){
    			if(j > i + 1 && num[j] == num[j-1])
    				continue;
    			l = j + 1; 
    			r = num.size() - 1;
    			while( l < r ){
    				sum = num[i] + num[j] + num[l] + num[r];
    				if( sum < target ){
    					++ l;
    				}else if( sum > target ){
    					-- r;
    				}else if(l != j + 1 && num[l] == num[l-1]){
    					++ l;
    				}else if((r != (num.size() - 1)) &&  num[r] == num[r+1]){
    					-- r;
    				}else{
    					vector<int> v ; 
    					v.push_back(num[i]) ; v.push_back(num[j]) ;
    					v.push_back(num[l]) ; v.push_back(num[r]) ;
    					result.push_back(v);
    					++ l ; 
    					-- r ;
    				}
    			}
    		}
    	}
    	return result;
    }
};


int main(){
	//int a[] = {1, 0, -1, 0,  -2 , 2};
	//int a[] = {5,5,3,5,1,-5,1,-2};
	int a[] = {-3,-2,-1,0,0,1,2,3};
	vector<int> v(a , a + sizeof(a) / sizeof(int));
	Solution sol;
	vector< vector<int> > result = sol.fourSum(v, 0);
	for(int i = 0 ;i  < result.size(); ++ i){
		cout << "######: " ; 
		for(int j = 0 ; j < result[i].size(); ++ j)
			cout <<" " << result[i][j];
		cout << endl;
	}
	return 0;
}