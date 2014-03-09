#include<stdio.h>
#include<stdlib.h>
const int maxn = 1000001 ;
int a[maxn] ,ia[maxn] , b[maxn] , c[maxn] , ibs , n , k , mx[maxn] , mn[maxn] ; 

void qs(int l ,int r){
     if(l == r) return ;
     int i = l , j = r , x = ia[(l+r)/2] , tp ; 
     do{
         while(ia[i]<x)++i;
         while(ia[j]>x)--j;
         if(i<=j){
             tp=ia[i] ;ia[i]=ia[j] ;ia[j]=tp ;
             i++ ; j-- ;
         }
     }while(i<=j) ;
     if(i<r) qs(i,r);
     if(j>l) qs(l,j);
}

int bs(int x){
    int l = 1 , r = ibs , mid ;
    while(l<=r){
         mid =(l+r)>>1;
         if(b[mid]==x)  return mid;
         if(x < b[mid]) r = mid-1 ;
         if(x > b[mid]) l = mid+1 ;
    }
    return 0;
}

inline int lowbit(int x) { 
       return x&(-x) ;
}

void update(int x ,int  d){
     for( ; x < maxn ; x+=lowbit(x))  c[x]+=d ;
}

int getkth(int kth){
     int i , ans=0 , cnt=0 ;
     for(i = 22 ; i>=0 ; --i){
          ans+=1<<i ;
          if(ans>=maxn||cnt+c[ans]>=kth)  ans-=1<<i ; 
          else  cnt+=c[ans] ;
     }
     return ans+1 ;
}

int main(){
    int i;
    scanf("%d%d" ,&n ,&k);
    for(i = 1 ;i<= n ;++i)  {
          scanf("%d" ,&a[i]);  ia[i] = a[i] ;
    }//for(i = 1 ;i<=n ; ++i) printf("sort %d\n" , ia[i]);
    qs(1 , n) ;    //for(i = 1 ;i<=n ; ++i) printf("sort %d\n" , ia[i]);
    b[1] = ia[1] ; ibs = 1 ;
    for(i = 2 ; i<=n ; ++i)
        if(ia[i]!=b[ibs])  b[++ibs] = ia[i] ;  //for(i = 1 ;i<=ibs ;++i) printf("value %d\n" , b[i]); 
    for(i = 1 ; i<=n ; ++i) a[i] = bs(a[i]) ;
    for(i = 0 ; i< maxn ; ++ i)  c[i] = 0 ;
    for(i = 1 ; i< k ; ++i)  update(a[i] , 1);
    for(i = k ; i <=n ; ++ i){
         update(a[i] , 1 );  
         //printf("%d %d\n" , b[getkth(1)] , b[getkth(k)] );
         mn[i] = b[getkth(1)] ;  mx[i] =  b[getkth(k)] ;
         update(a[i-k+1] , -1);
    } 
    printf("%d" ,mn[k]); for(i = k+1 ; i<=n ;++i) printf(" %d" , mn[i]);  printf("\n");
    printf("%d" ,mx[k]); for(i = k+1 ; i<=n ;++i) printf(" %d" , mx[i]);  printf("\n");
    //system("pause");
    return 0 ;
}
