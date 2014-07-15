#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;


#define unordered_set set

struct node{
	int a, b, c ; 
	node(int _a, int _b, int _c): a(_a), b(_b), c(_c){}
};

bool operator < (const node &x, const node &y){
		if(x.a != y.a)
			return x.a < y.a ;
		if(x.b != y.b)
			return x.b < y.b;
		return x.c < y.c;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	int i, j, k ;
    	set<node> nset;
    	sort(num.begin(), num.end());
    	for(i = 0 ; i < num.size(); ++ i){
	    	unordered_set<int> iset;
    		for(j = 0 ; j < i ; ++ j){
    			unordered_set<int>::iterator it = iset.find(-num[i]-num[j]);
    			if(it != iset.end())
    				nset.insert(node(-num[i]-num[j], num[j], num[i]));
    			iset.insert(num[j]);
    		}
    	}
    	vector< vector<int> > result ;
    	for(set<node>::iterator it = nset.begin(); it!=nset.end(); ++it){
    		vector<int> v ;
    		v.push_back(it->a);
    		v.push_back(it->b);
    		v.push_back(it->c);
    		result.push_back(v);
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