#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define unordered_set set
#define unordered_map map

bool cmp(vector<int> a, vector<int> b){
	if(a[0] != b[0])
		return a[0] < b[0];
	if(a[1] != b[1])
		return a[1] < b[1];
	return a[2] < b[2];
}

bool eq(vector<int> a, vector<int> b){
	return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

class Solution {
public:
	typedef unordered_set<int>::iterator uit;
    vector<vector<int> > threeSum(vector<int> &num) {
    	int i , j , k, c;
    	vector< vector<int> > result;
    	vector< vector<int> > que ;
    	sort(num.begin(), num.end());
    	for(i = 2 ; i < num.size(); ++ i){
    		unordered_set<int> uset; 
    		c = - num[i];
    		for(j = 0 ; j < i ; ++ j){
    			uit it = uset.find(c - num[j]); 
    			if(it != uset.end()){
    				vector<int> v; 
    				v.push_back(*it);
    				v.push_back(num[j]);
    				v.push_back(-c);
    				result.push_back(v);
    			}
    			uset.insert(num[j]);
    		}
    	}
    	//return result;
    	if(result.size() == 0)
    		return result;
    	sort(result.begin(), result.end(), cmp);
    	j = 0;
    	que.push_back(result[0]);
    	for(i = 1 ; i < result.size() ; ++ i)
    		if(!eq(result[i], result[j])){
    			que.push_back(result[i]);
    			j = i ; 
    		}
    	return que;
    }
};

int main(){
	int n , i ; 
	while(cin >> n ){
		int x ; 
		vector<int> num;
		for(int i = 0 ;i < n ; ++ i){
			cin >> x ;
			num.push_back(x);
		}
		Solution sol ;
		vector< vector<int> > result = sol.threeSum(num);
		for(int i = 0;  i < result.size(); ++ i){
			cout << "########";
			for(int j = 0 ; j < result[i].size(); ++ j){
				cout << " " << result[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}