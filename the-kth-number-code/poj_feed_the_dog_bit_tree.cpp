#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std ;
const int maxn = 100005 ;
const int maxq = 50001  ; 

int n ,q , a[maxn] , c[maxn] , b[maxn] ;
int x0[maxq] , x1[maxq], kth[maxq] , id[maxq] , ans[maxq]; 


void asort(int l , int r ){
     int i = l  , j = r , x = a[(l+r)>>1] ;
     if(l == r)  return ;
     do{
          while(a[i]<x) i++ ; 
          while(x<a[j]) j-- ; 
          if(i<=j){ 
            swap(a[i],a[j]); 
            swap(c[i] ,c[j]);
            i++ ; j-- ;
          }
     }while(i<=j) ;
     if(i<r)  asort(i , r);
     if(l<j)  asort(l , j); 
}

void query_sort(int l , int r){
     int i  = l , j = r , x = x0[(l+r)>>1] ;
     if(l == r)  return ; 
     do{ 
         while(x0[i]<x) i ++ ; 
         while(x<x0[j]) j -- ; 
         if(i<=j){
             swap(x0[i] , x0[j]) ; 
             swap(x1[i] , x1[j]);
             swap(kth[i], kth[j]);
             swap(id[i], id[j]);
             i++  ; j-- ;
         }
     }while(i<=j) ; 
     if(i<r) query_sort(i , r);
     if(l<j) query_sort(l , j);
}

int arr[maxn] ;

inline int lowbit(int x) {  return x&(-x) ;}

void update(int x ,int d){
     for( ; x<maxn ; x+=lowbit(x))  arr[x]+=d ;
}

int _find(int k ){
    int i ,cnt = 0 , ans = 0 ; 
    for(i = 20 ; i>=0 ; --i){
          ans +=1<<i ;
          if(ans >= maxn || cnt + arr[ans]>=k)  ans-=1<<i ;
          else cnt += arr[ans] ; 
    }
    return ans + 1 ;
}
/*
void show(int *fuck , int len){
     printf("show array : ");
     for(int i = 1 ; i<= len ;++ i) printf("     %d" , fuck[i]);
     printf("\n");
}*/


int main(){
    int i , s ;     
    scanf("%d%d"  , &n , &q);
    for(i = 1 ; i <=n ; ++ i){
           scanf("%d" , &a[i] ); c[i] = i ; 
    }
    for(i = 1 ; i <=q ; ++ i){
           scanf("%d%d%d" , &x0[i] , &x1[i], &kth[i]);  id[i] = i ;
    }
    memset(arr , 0 , sizeof(arr));
    asort(1 , n ); 
    query_sort(1 , q );   //show(x0 , q);  show(x1 , q) ; show(kth ,q);
    for(i = 1 ; i<= n ; ++ i)  b[c[i]] = i ;   //show(b ,n);
    x0[0] = x1[0] = 0 ; 
    for(i = 1 ; i <= q ; ++ i){
        if(i == 1){
             for(s = x0[i] ; s <= x1[i] ;++ s)  update(b[s] , 1);
        }else{
             if(x0[i] > x1[i-1]){
                  for(s = x0[i-1] ; s <= x1[i-1] ; ++ s)  update(b[s], -1);
                  for(s = x0[i] ; s <= x1[i] ; ++ s)  update(s , 1 );
             }else{
                  for(s = x0[i-1] ; s < x0[i] ; ++ s) update(b[s] , -1);
                  for(s = x1[i-1]+1 ; s<= x1[i] ; ++ s) update(b[s] ,1);
             }
        }
        //printf("kth:%d\n" , _find(kth[i]));
        ans[id[i]] = a[_find(kth[i])] ;
    }
    for(i = 1 ; i <= q; ++ i)  printf("%d\n", ans[i]);
    //system("pause");
    return 0 ;
}
