#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std ; 

int main(){
    int n , p , k ; 
    while(scanf("%d%d%d", & n, & p , & k ) !=EOF ){
        int l , r ; 
        if(p -k < 1 )
            l = 1 ; 
        else
            l = p - k ; 
        if(p + k > n ) 
            r = n ; 
        else 
            r = p + k ; 

        int first = 1;

        if(l != 1){
            printf("<<") ; 
            first = 0 ; 
        }

        for(int i = l ; i <= r ; ++ i) {
            if(first) {
                first = 0 ; 
            } else{
                printf(" ") ;
            }
            if(i == p )
                printf("(%d)", i ) ; 
            else
                printf("%d", i ) ; 
        }
        if(r != n ) 
            printf(" >>") ;
        printf("\n") ; 
    }
    return 0 ;
}
