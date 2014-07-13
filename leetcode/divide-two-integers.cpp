#include <iostream>
using namespace std;

class Solution {
public:

	typedef long long lld;
	lld mul(lld x, lld y){
		lld ret = 0; 
		while(y){
			if(y & 1) ret = ret + x;
			y >>= 1;
			x += x;
		}
		return ret;
	}

	lld div(lld x, lld y){
		if( x < y  ) return 0;
		if( x == y ) return 1;
		lld l = 1 , r = x, mid, ret = 1, temp;
		while(l <= r){
			mid = (l + r) >> 1;
			temp = mul(mid, y);
			if(temp == x) return mid; 
			if(temp < x ){
				ret = mid ; l = mid + 1;
			}
			if(temp > x){
				r = mid - 1;
			}
		}
		return ret;
	}

    int divide(lld dividend, lld divisor) {
    	if( dividend == 0 ) return 0;
    	lld l , r , mid, flag, f1 = 1, f2 = 1; 
    	if(dividend < 0 ){
    		dividend = -dividend;
    		f1 = 0;
    	}
    	if(divisor < 0){
    		divisor = -divisor;
    		f2 = 0;
    	}
    	return ( f1 ^ f2 ? -div(dividend, divisor): div(dividend, divisor));
    }
};

int main(){
	Solution sol ;
	cout << sol.divide( 5, 2) << endl;
	cout << sol.divide( 1, 2) << endl;
	cout << sol.divide( 0, 2) << endl;
	cout << sol.divide( 1, 1) << endl;
	cout << sol.divide( 1000000, 2) << endl;
	cout << sol.divide( -1000000, 2) << endl;
	cout << sol.divide( -1000000, -2) << endl;
	cout << sol.divide( 1000000, -3) << endl;
	return 0;
}