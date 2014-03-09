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
     int i  = l , j = r , x = (l+r)>>1 , t ;
     if(l == r)  return ;  
     t = rand()%(r-l)+l ; swap(x0[t] , x0[x]) ; swap(x1[t] ,x1[x]);  swap(kth[t] ,kth[x]);  swap(id[t] ,id[x]);
     x = x0[(l+r)>>1] ; 
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

int get_sum(int x){
    int res = 0 ; 
    for( ; x ; x-=lowbit(x))  res += arr[x] ; 
    return res ;
}

/*
int _find(int k ){
    int i ,cnt = 0 , ans = 0 ; 
    for(i = 20 ; i>=0 ; --i){
          ans +=1<<i ;
          if(ans >= maxn || cnt + arr[ans]>=k)  ans-=1<<i ;
          else cnt += arr[ans] ; 
    }
    return ans + 1 ;
}*/

int other_find(int k){
    int i , l , r , mid ,t0 ,t1 , ans ;
    l = 1 ; r = n ; 
    while(l<=r){
          mid =(l+r)>>1 ;
          t0 = get_sum(mid-1)+1;  
          if(k == t0 ){
                ans = mid ; l = mid + 1 ;
          }else if(k < t0 ){
                r = mid - 1 ;
          }else {
                l = mid + 1 ;
          }
    }
    return ans ;
}

int main(){
    srand(1);
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
    query_sort(1 , q ); 
    for(i = 1 ; i<= n ; ++ i)  b[c[i]] = i ;  
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
        ans[id[i]] = a[other_find(kth[i])] ;
    }
    for(i = 1 ; i <= q; ++ i)  printf("%d\n", ans[i]);
    //system("pause");
    return 0 ;
}
