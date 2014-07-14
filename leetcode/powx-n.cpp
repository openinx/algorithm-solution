#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


// be cation that n may be -2147483648 ,  if abs(n) then overflow..
class Solution {
public:
    double pow(double x, int n) {
    	double res = 1 ; 
    	long long p = n;
    	if(p == 0) return fabs(x) < 1e-8 ? 0 : 1;
    	if( p < 0 ){
    		x =  1.0 / x ;
    		p = -p ;
    	}
    	while(p){
    		if( p & 1 ) 
    			res = res * x ; 
    		p >>= 1;
    		x *= x;
    	}
    	return res;
    }
};

int main(){
	Solution sol;
	cout << sol.pow(1.0, -2147483648) << endl;
	return 0;
}