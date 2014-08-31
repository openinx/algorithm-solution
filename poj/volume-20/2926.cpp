#include <iostream>
#include <stdio.h>
#include <string.h>

const static int maxn = 100001 ; 

using namespace std;

int n;
double x[maxn][5];

int main(){
	double maxv, minv, ans = 0 ;
	scanf("%d", &n );
	for(int i = 0 ; i < n ; ++ i){
		for(int j = 0 ; j < 5 ; ++ j)
			scanf("%lf", &x[i][j]);
	}
	ans = -1e100;
	for(int k = 0 ; k < (1<<5) ; ++ k){
		maxv  = -1e100; 
		minv  = +1e100;
		for(int i = 0 ; i < n ; ++ i){
			double sumx = 0; 
			for(int j = 0 ; j < 5 ; ++ j)
				if(k & (1<<j)){
					sumx = sumx + x[i][j];
				}else{
					sumx = sumx - x[i][j];
				}
			maxv = max(maxv, sumx);
			minv = min(minv, sumx);
		}
		ans = max(ans, maxv - minv);
	}
	printf("%0.2lf\n", ans);
	return 0 ;
}
