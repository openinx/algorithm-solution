#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:

	bool check(int *x, int k){
		for(int i = 0 ; i < k ; ++ i)
			if(x[k] == x[i] || abs(x[k] - x[i]) == abs(k - i))
				return false;
		return true;
	}

    int totalNQueens(int n) {
    	int *x = new int[n], total = 0, k = 0;
    	x[0] = -1;
    	while(k >= 0){
    		x[k] += 1;
    		while(x[k] < n && !check(x, k)) x[k] += 1;
    		if(x[k] < n){
    			if(k == n - 1)
    				++total;
    			else
    				x[++k] = -1;
    		}else{
    			--k;
    		}
    	}
    	delete x;
    	return total; 
    }
};

int main(){
	for(int i = 4 ; i <= 12 ; ++ i){
		Solution sol ;
		cout << sol.totalNQueens(i) << endl;
	}
	return 0;
}