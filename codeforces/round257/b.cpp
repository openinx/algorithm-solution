#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

typedef long long lld;
const lld mod = 1000000007;

lld t[2][2];

void mul(lld a[2][2], lld b[2][2]){
	lld i , j , k, sum = 0 ;
	for(i = 0 ; i < 2 ;++ i)
		for(j = 0 ; j < 2 ; ++ j){
			sum = 0 ; 
			for(k = 0 ; k < 2 ; ++ k){
				sum = ( sum + a[i][k] * a[k][j]) % mod ;
				sum = ( sum + mod ) % mod;
			}
			t[i][j] = sum;
		}
}

lld calc(lld n, lld f2, lld f1){
	int i , j;
	if(n == 1) return f1; 
	if(n == 2) return f2;
	lld a[2][2] = {{1, -1},{1, 0}}, res[2][2] = {{1, 0}, {0, 1}}, ans ;
	n -- ;
	while(n){
		if(n & 1){
			mul(res, a);
			for(i = 0 ; i < 2 ; ++ i) 
				for(j = 0 ; j < 2 ; ++ j)
					res[i][j] = t[i][j] ;
		}
		n >>= 1;
		mul(a, a);
		for(i = 0 ; i< 2; ++i)
			for(j = 0 ; j < 2 ; ++ j)
				a[i][j] = t[i][j];
	}
	ans = a[1][0] * f2  % mod + a[1][1] * f1 % mod;
	ans = (ans + mod ) % mod ;
	return ans;
}

int main(){
	lld f1, f2, n ;
	while( cin >> f1 >> f2 >> n)
		cout << calc(n, f2, f1) << endl;
	return 0;
}