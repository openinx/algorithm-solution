#include<stdio.h>
#include<stdlib.h>
#define maxn 10001

int qs(int *a , int l , int r , int k){
     if(l == r)  return a[l] ;
     int i = l , j = r , x = a[(l+r)>>1] , temp ; 
     do{
         while(a[i] < x) ++ i ; 
         while(a[j] > x) -- j ; 
         if(i <= j){
             temp = a[i] ;  a[i] = a[j] ,  a[j] = temp ;  
             i++ ;  j-- ; 
         }
     }while(i<=j) ;
     if(k <= j)  return qs(a , l , j , k);
     if(k >= i)  return qs(a , i , r , k);
     return x ;
}

int main(){
    int N , M , data[maxn] , t[maxn] , l , r ,k , i ; 
    scanf("%d%d" ,&N , &M);
    for(i = 1 ; i <= N ; ++ i)  scanf("%d" , &data[i]);
    while(M--){
         scanf("%d%d%d" ,&l ,&r ,&k);
         for(i = l ; i<=r ; ++i)  t[i] = data[i] ;  // for(i = 1 ; i<= k ; ++ i  ) printf("  %d" , t[i]);  printf(" end \n");
         printf("%d\n" , qs(t , l , r , k+l-1));
    }
    //system("pause");
    return 0 ;
}
