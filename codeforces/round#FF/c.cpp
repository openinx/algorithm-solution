#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXN = 100005;

int n , a[MAXN], l[MAXN], r[MAXN];

int solve(){
	if(n == 1) return 1;
	int i , ans = 0; 
	l[0] = 1;
	for(i = 1 ; i < n; ++ i)
		l[i] = (a[i] > a[i-1] ? l[i-1] + 1 : 1);
	r[n-1] = 1;
	for(i = n-2; i >= 0 ; --i)
		r[i] = (a[i] < a[i+1] ? r[i+1] + 1 : 1);
	ans = max(r[1] + 1 , ans );
	ans = max(l[n-2] + 1, ans );
	for( i = 1 ; i <= n-2 ; ++ i){
		if(a[i+1] - a[i-1] >= 2)
			ans = max(ans , l[i-1] + r[i+1] + 1);
		ans = max(r[i+1] + 1 , ans );
		ans = max(l[i-1] + 1 , ans );
	}
	return ans;
}

int main(){
	while(cin >> n){
		for(int i = 0 ; i < n; ++ i)
			scanf("%d", &a[i]);
		cout << solve() << endl;
	}
}