#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std; 

struct node{
	int hi , idx ; 
	node(int _hi, int _idx): hi(_hi), idx(_idx){}
};

bool cmp(const node &a , const node &b){
	return a.hi < b.hi ;
}

class Solution {
public:
    int candy(vector<int> &ratings) {
    	vector< node > lower ; 
    	vector< int > high ; 
    	high.push_back(0);
    	for(int i = 1 ; i < ratings.size(); ++ i){
    		if(ratings[i] == ratings[i-1])
    			high.push_back(high.back());
    		if(ratings[i-1] < ratings[i])
    			high.push_back(high.back() + 1);
    		if(ratings[i-1] > ratings[i])
    			high.push_back(high.back() - 1);
    	}

    	lower.push_back(node(0, 0));
    	for(int i = 1 ; i <  high.size() - 1 ; ++ i){
    		if(( high[i] <= high[i-1] && high[i] < high[i+1])
    		 || (high[i] < high[i-1] && high[i] <= high[i+1])
    		 || (high[i] == high[i-1] && high[i] == high[i+1])) 
    			lower.push_back(node(high[i], i));
    	}
    	lower.push_back(node(high.back(), high.size()-1));
    	sort(lower.begin(), lower.end(), cmp);

    	int *ret = new int[ratings.size() + 1];
    	int sum = 0 , idx;
    	for(int i = 0 ; i < ratings.size() ; ++ i) ret[i] = 0 ;
    	for(int i = 0 ;i < lower.size() ;  ++ i)
    		if(ret[lower[i].idx] <= 0){
	    		idx = lower[i].idx ;
	    		ret[idx] = 1 ;
	    		for(int j = idx+1; j >= 0 && j < ratings.size() && ratings[j-1] < ratings[j] && ret[j] <= 0; ++ j){
	    			ret[j] = ret[j-1] + 1 ;
	    		}
	    		for(int j = idx-1; j >= 0 && j < ratings.size() && ratings[j+1] < ratings[j] && ret[j] <= 0; --j){
	    			ret[j] = ret[j+1] + 1 ;
	    		}
    	}
    	for(int i = 0 ; i < ratings.size() ; ++ i) {
    		sum += ret[i];
    	}
    	return sum;
    }
};

int main(){
	int x , n;
	vector<int > array ;
	while(cin >> n){
		array.clear();
		for(int i = 0 ; i < n ; ++ i) {
			cin >> x ; 
			array.push_back(x);
		}
		Solution sol;
		cout << sol.candy(array) << endl ;
	}
}