#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
	int k , x[26], maxval, res = 0; 
	char s[1001];
	scanf("%s%d", s, &k);
	for(int i = 0 ;i < 26 ; ++ i)
		scanf("%d", &x[i]);
	maxval = x[0];
	for(int i = 1 ; i < 26 ; ++ i){
		maxval = max(x[i],maxval);
	}
	int len = strlen(s);
	for(int i = 0 ; i < len; ++ i){
		res += x[s[i] - 'a'] * (i+1);
	}
	res += maxval * (k * len + (1+k) * k /2 );
	printf("%d\n", res);
	return 0 ;
}