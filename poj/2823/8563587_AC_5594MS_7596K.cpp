#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std ;
const int maxn = 1000006 ;
int n , k ; 

struct deque{
       int head , tail , q[maxn][2] ;
       void init(){
            head = 0 ; tail = -1 ;
       }
       int getmax(int i , int val  ){
            while(tail>=head && q[tail][1]<=val)  tail--; 
            ++ tail ; q[tail][0] = i ; q[tail][1] = val ;
            while(tail>=head && q[head][0]<=i-k)   head++ ;
            return q[head][1] ;
       }
       int getmin(int i , int val ){
           while(tail>=head && q[tail][1] >= val) tail-- ; 
           ++ tail ; q[tail][0] = i ;  q[tail][1] = val ; 
           while(tail>=head && q[head][0]<=i-k) head++ ; 
           return q[head][1]  ; 
       }
};
deque Qmx , Qmn ; 


int main(){
    int i , x[maxn] ; 
    scanf("%d%d" , &n , &k);  Qmx.init() ; Qmn.init() ;
    for(i = 0 ; i < n ; ++ i) scanf("%d" , &x[i]);
    for(i = 0 ; i < k-1 ; ++ i){
             Qmx.getmax(i , x[i] ) ; Qmn.getmin(i , x[i] );
    }
    printf("%d" , Qmn.getmin(k-1 , x[k-1]));  for(i = k ; i < n ; ++ i) printf(" %d" , Qmn.getmin(i , x[i]));  printf("\n");  
    printf("%d" , Qmx.getmax(k-1 , x[k-1]));  for(i = k ; i < n ; ++ i) printf(" %d" , Qmx.getmax(i , x[i]));  printf("\n");  
    return 0 ;
}
