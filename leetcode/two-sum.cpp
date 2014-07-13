#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


#define unordered_set set
#define unordered_map map

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) { 
    	unordered_map<int,int> nmap ;
    	vector<int> result ;  
    	for(int i = 0 ; i < numbers.size() ; ++ i){
    		int index = nmap[ target - numbers[i] ] ; 
    		if( index != 0 ){
    			result.push_back(index) ; 
    			result.push_back(i+1);
    			return result;    		
    		}
    		nmap[ numbers[i] ] =  i + 1;
    	}
    	return result;
    }
};

int main(){
	Solution sol ;
}