#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


typedef long long lld;
const lld mod = 1000000007;


lld f(lld x){
	return (( x % mod + mod  ) % mod  + mod ) % mod;
}

int main(){
	lld x , y , n; 
	while( cin >> x >> y >> n){
		n = ( n - 1 ) % 6 + 1;
		if( n == 1) cout << f(x) << endl;
		if( n == 2) cout << f(y) << endl;
		if( n == 3) cout << f(y - x) << endl;
		if( n == 4) cout << f(-x) << endl;
		if( n == 5) cout << f(-y) << endl;
		if( n == 6) cout << f(x-y) << endl;
	}
	return 0 ;
}