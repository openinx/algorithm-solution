#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution{
public:
	vector<vector<int> > threeSum(vector<int> &num){
		int i , j, k, c, cnt; 
		vector<vector<int> > result;
		if(num.size() < 3) return result;
		sort(num.begin(), num.end());
		for(i = 2 ; i < num.size(); ++ i)
			if(i < num.size() - 1 && num[i] == num[i+1]){
				continue;
			}else{
				j = 0 ;
				k = i-1;
				c = -num[i] ;
				while(j < k){
					if(num[j] + num[k] > c)
						--k;
					else if(num[j] + num[k] < c)
						++j;
					else{
						vector<int> v ;
						v.push_back(num[j]);
						v.push_back(num[k]);
						v.push_back(num[i]); 
						result.push_back(v);
						while(j < k && num[j] + num[k] == c) --k;
					}
				}
		}
		return result;
	}
};


int main(){
	int n; 
	while( cin >> n){
		int x ; 
		vector<int> num;
		Solution sol;
		for(int i = 0 ;i < n ; ++i){
			cin >> x; 
			num.push_back(x);
		}
		vector< vector<int> > result = sol.threeSum(num);
		for(int i = 0 ;i < result.size(); ++ i){
			cout << "###### "; 
			for(int j = 0 ; j < result[i].size(); ++ j)
				cout << "  " << result[i][j];
			cout << endl;
		}
	}
	return 0;
}