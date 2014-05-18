#include<iostream>
#include<stdlib.h>
#include<stdio.h>

int main(){
    int n , k, x, count = 0  ; 
    while(scanf("%d%d", &n, &k) != EOF ){
        count = 0 ; 
        for(int i = 0 ; i < n ; ++ i){
            scanf("%d", &x);
            if(x + k <= 5){
                count ++ ; 
            }
        }
        printf("%d\n", count / 3);
    }
    return 0 ;
}
