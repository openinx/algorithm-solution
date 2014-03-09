#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 10005 

struct node{
    int l , r ,  c ; 
};
node t[maxn*6] ;
int  x[maxn] , y[maxn] , b[2*maxn] , bsi , fuck[2*maxn] ,vis[maxn] ;

void qs(int *a , int l , int r){
     if( l>=r )  return ; 
     int i = l , j = r , x = a[(l+r)>>1] , tmp ; 
     do{
         while(a[i]<x) ++ i  ; 
         while(a[j]>x) -- j  ; 
         if(i<=j){
             tmp = a[i] ; a[i] = a[j] ; a[j] = tmp ;
             ++ i ; -- j;
         }
     }while(i<=j);
     if(i<r) qs(a , i , r );
     if(l<j) qs(a , l , j );
}

int bs(int x){
    int l = 1 , r = bsi , mid ; 
    while(l<=r){
         mid = (l+r)>>1 ;
         if(b[mid] == x)  return mid  ;
         if(x < b[mid])   r = mid - 1 ; 
         if(x > b[mid])   l = mid + 1 ;
    }
    return  0 ;
}

void build(int x , int l ,int r){
     t[x].l = l , t[x].r = r , t[x].c = 0 ; 
     if(l == r)  return ;
     int mid = (t[x].l + t[x].r)>> 1 ; 
     build(x<<1 , l , mid );
     build((x<<1)+1 , mid+1 , r);
}

void down(int x){
     if(t[x].c > t[x<<1].c )  t[x<<1].c = t[x].c  ; 
     if(t[x].c > t[(x<<1)+1].c)  t[(x<<1)+1].c = t[x].c ; 
}

void ins(int x , int l , int r , int c){
     if(t[x].l == l && t[x].r == r){
          t[x].c = c ;   return ;
     }
     int mid = (t[x].l + t[x].r)>>1 ; 
     if(r <= mid )
          ins(x<<1 , l , r , c );
     else if(mid < l )
          ins((x<<1)+1 , l , r , c);
     else {
          ins(x<<1 , l , mid , c);
          ins((x<<1)+1  , mid+1 , r , c);
     }
}

void query(int x){
     if(t[x].l == t[x].r) {
         vis[t[x].c] = 1 ; return ;
     }
     down(x);
     query(x<<1);
     query((x<<1)+1);
}

int main(){
    int acase , i , ans , n  ;
    scanf("%d" ,&acase);
    while(acase--){
          scanf("%d" , &n);
          for(i = 1 , bsi = 0 ; i<=n ; ++i){
               scanf("%d%d" ,&x[i] , &y[i]);
               fuck[2*i-1] = x[i] ; fuck[2*i] = y[i] ;
          }
          qs(fuck , 1 , 2*n );
          b[1] = fuck[1] ; 
          for(i = 2 , bsi = 1 ; i <= 2*n ; ++i)
              if(fuck[i] != b[bsi])  b[++bsi] = fuck[i] ; 
          for(i = 1 ; i <= n ; ++ i){
              x[i] = bs(x[i]);  y[i] = bs(y[i]);
          }
          build(1 , 1 , bsi);
          for(i = 1 ; i <= n ; ++ i)
              ins(1 , x[i] , y[i] , i);
          for(i = 1 ; i <= n ; ++ i)  vis[i] = 0 ;
          query(1);
          ans = 0 ;
          for(i = 1 ; i <= n ; ++ i)  
              ans += vis[i] ; 
          printf("%d\n"  , ans);
    }
    //system("pause");
    return 0 ;
}



