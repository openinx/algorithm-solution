#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std; 
const int maxn = 100001 ;
const int maxk = 20 ; 

int tr[maxk][maxn] , s[maxk][maxn] ;
int n , m , a[maxn] , b[maxn];

void qs(int l ,int r){
     if(l == r)  return ; 
     int i = l , j = r , x = a[(l+r)>>1] , temp ;
     do{
          while(a[i] < x) ++ i ; 
          while(a[j] > x) -- j ; 
          if(i <= j){
               temp = a[i] ; a[i] = a[j] ; a[j] = temp ;
               temp = b[i] ; b[i] = b[j] ; b[j] = temp ;
               i++ ;  j-- ;
          }
     }while(i<=j) ; 
     if(i < r)  qs(i , r);
     if(j > l)  qs(l , j);
}

void build(int d , int l , int r ){
     if(l == r)  return ; 
     int mid = (l + r)>>1 , i , j , k ;
     i = l ;  j = mid + 1 ;
     for(k = l ; k <= r ; ++ k){
          s[d][k] = s[d][k-1] ; 
          if(tr[d][k] <= mid && i <= mid ){
                s[d][k] ++ ;    
                tr[d+1][i++] = tr[d][k] ;  
          }else{
                tr[d+1][j++] = tr[d][k] ;
          }
     }
     build(d+1 , l , mid );  
     build(d+1 , mid+1 , r );
}

int query(int d ,int left ,int right , int  l ,int r ,int k ){
    if(left == right)  return tr[d][left] ;
    int mid = (left+right)>>1 ;
    if( k <= s[d][r] - s[d][l-1])   
         return query(d+1 , left , mid  , left+s[d][l-1]-s[d][left-1] , left+s[d][r]-s[d][left-1]-1 , k );
    else 
         return query(d+1 , mid+1,right , mid+1+(l-left)-(s[d][l-1]-s[d][left-1]) , mid+(r-left+1)-(s[d][r]-s[d][left-1]) , k-(s[d][r]-s[d][l-1]));
}

int main(){
    int i , l , r , kth ; 
    scanf("%d%d" , &n , &m);
    for(i = 1 ; i<=n ; ++ i)  {
          scanf("%d" ,&a[i]);   b[i] = i ; 
    }
    qs(1 , n);
    for(i = 1 ; i<=n ; ++ i)  tr[1][b[i]] = i ;
    for(i = 0 ; i<maxk ; ++ i)  s[i][0] = 0 ;
    build(1 ,1 , n );
    for(i = 1 ; i<=m ; ++ i){
           scanf("%d%d%d" ,&l , &r ,&kth);
           printf("%d\n" ,a[query(1 , 1 , n , l , r , kth)]) ;
    }
    //system("pause");
    return 0 ;
}

