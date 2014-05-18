#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXN 100005

int main(){
    int n, i, a[MAXN], b[MAXN], ac[MAXN], bc[MAXN] ; 
    while(scanf("%d", &n) !=EOF ){
        memset(ac , 0 , sizeof(ac));
        memset(bc , 0 , sizeof(bc));
        for(int i = 0 ; i < n ; ++ i){
            scanf("%d%d", &a[i], &b[i]);
            ac[ a[i] ] += 1 ; 
            bc[ b[i] ] += 1 ; 
        }
        for(int i = 0 ; i < n ; ++ i){
            int delta = ac[ b[i] ] ; 
            printf("%d %d\n", n - 1 + delta , n - 1 - delta);
        }
    }
    return 0 ;
}
