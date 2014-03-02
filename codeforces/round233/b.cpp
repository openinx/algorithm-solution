#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;


int main(){
    int n  , step ; 
    char s[50], i = 0  ; 
    while(scanf("%d%s", &n, s ) !=EOF ) {
        i = 0 ; 
        step = 0 ; 
        do{
            while(s[i] == 'R'  && i < n )  i ++ ;
            if( i == n )
                break;
            if(s[i] == 'B') s[i] = 'R' ;
            for(int k = 0 ; k < i ; ++ k) s[k] = 'B' ;
            step ++ ;
            i = 0 ; 
        }while(1) ;
        printf("%d", step) ;
    }
    return 0 ;
}
