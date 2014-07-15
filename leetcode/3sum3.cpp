#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct mycmp{
	bool operator() (const vector<int> a, const vector<int> b) const{
		if(a[0] != b[0]) 
			return a[0] < b[0];
		if(a[1] != b[1])
			return a[1] < b[1];
		return a[2] < b[2];
	}
};

class Solution{
public:
	vector<vector<int> > threeSum(vector<int> &num){
		int i , j, k, c, cnt; 
		map<vector<int>, bool, mycmp> imap;
		vector<vector<int> > result;
		if(num.size() < 3) return result;
		sort(num.begin(), num.end());
		for(i = 0 ; i < num.size(); ++ i){
				j = 0 ;
				k = i-1;
				c = -num[i] ;
				while(j < k){
					if(num[j] + num[k] > c) --k;
					else if(num[j] + num[k] < c) ++j;
					else{
						vector<int> v ;
						v.push_back(num[j]); v.push_back(num[k]); v.push_back(num[i]); 
						imap[v] = true;
						while(j < k && num[j] + num[k] == c) --k;
					}
				}
		}
		for(map<vector<int>, bool, mycmp>::iterator it=imap.begin(); it!=imap.end(); ++it)
			result.push_back(it->first);
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