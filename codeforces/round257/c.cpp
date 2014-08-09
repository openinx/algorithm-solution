#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long lld;

int main(){
	lld n , m , k , ans;
	while( cin >> n >> m >> k ){
		if( k > n + m - 2) {
			cout << -1 << endl;	 continue;
		}
		lld ans = 0, x, start = max(k/2 - 100, (lld)0), end = min(k / 2 + 100, min(m - 1, k)); 
		for( x = start ; x <= end; ++ x){
			lld a = ( m % (x + 1) == 0 ? m / (x + 1): m % (x + 1));
			lld b = ( n % (k - x + 1) == 0 ? n / (k - x + 1): n % (k - x + 1));
			lld t = a * b; 
			if(ans < t)
				ans = t;
		}
		cout << ans << endl;
	}
	return 0 ;
}