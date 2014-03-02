#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define maxk 20 
#define maxn 500005
typedef  __int64  lld ; 
lld tr[maxk][maxn] , s[maxk][maxn] ;

struct node{
      lld x , pos ;
}; 
node h[maxn] ; 
lld  hs , n , K , L , R , A[maxn] , Ai[maxn] ,b[maxn] , c[maxn];

void up(lld i ){
     lld j ; 
     node temp ;
     while(i>1){
          j = i/2 ; 
          if(h[i].x > h[j].x){
             temp = h[i] ;  h[i] = h[j] ; h[j] = temp ;
          }else  break ;
          i = j ;
     }
}

void down(lld i){
     lld j ; 
     node temp ;
     while(2*i<=hs){
          j = 2*i ; 
          if(j+1<=hs && h[j+1].x > h[j].x ) ++ j ;
          if(h[i].x < h[j].x ){
             temp = h[i] ; h[i] = h[j] ; h[j] = temp ;
          }else break ;
          i = j  ;
     }
}

void build(lld d ,lld l , lld r ){
     if(l == r)  return  ;
     lld i , mid = (l+r)>>1 , j=l , k=mid+1  ;
     for(i = l ; i <= r ; ++ i){
           s[d][i] = s[d][i-1] ; 
           if(tr[d][i] <= mid){
               s[d][i]++ ;  
               tr[d+1][j++] = tr[d][i]; 
           }else{
               tr[d+1][k++] = tr[d][i];
           }
     }
     build(d+1 ,l , mid);
     build(d+1 , mid+1 , r);
}

lld getkth(lld d ,lld lp ,lld rp , lld l , lld r , lld k){
    if(lp == rp )  return tr[d][lp] ;
    lld mid = (lp + rp)>>1 ; 
    if(k<=s[d][r]-s[d][l-1])
        return getkth(d+1 ,lp , mid , lp+s[d][l-1]-s[d][lp-1] , lp+s[d][r]-s[d][lp-1]-1 , k );
    else 
        return getkth(d+1 ,mid+1 , rp , mid+1+(l-lp)-(s[d][l-1]-s[d][lp-1]) , mid+(r-lp+1)-(s[d][r]-s[d][lp-1]) , k-(s[d][r]-s[d][l-1]) );
}
/*
void test_divid_tree(){
     lld i , nn , q , x ,y ,  k ;
     while(scanf("%I64d%I64d" , &nn ,&q)!=EOF){
         for(i=1;i<=nn;++i) scanf("%I64d" , &tr[1][i]);
         for(i = 0 ; i < maxk ; ++ i)  s[i][0] = 0 ;
         build(1 , 1 , nn);
         while(q--){
            scanf("%I64d%I64d%I64d" ,&x , &y  ,&k);
            printf("ans = %I64d\n" , getkth(1 , 1 , nn , x , y , k));
         }
     }
}
*/

void qs(lld *a , lld *ai , lld l , lld r){
     if(l == r)  return ; 
     lld i = l , j = r , x =a[(l+r)>>1] , tp ;
     do{
         while(a[i]>x) ++ i ;
         while(a[j]<x) -- j ; 
         if(i<=j){
              tp = a[i] ; a[i] = a[j] ; a[j] = tp ;
              tp =ai[i] ;ai[i] = ai[j]; ai[j]= tp ; 
              i++ ; j-- ;
         }
     }while(i<=j) ;
     if(i<r) qs(a ,ai , i , r);
     if(l<j) qs(a ,ai , l , j);
}

int main(){
    //test_divid_tree();
    lld ans , i ,val , pos , l , r , opt ; 
    scanf("%I64d%I64d%I64d%I64d" , &n ,&K , &L , &R);
    /*A[1] = 0 ; Ai[1] = 1 ;  ++ n ; 
    for(i = 2 ; i <= n ; ++ i){
            scanf("%I64d" , &A[i]);  Ai[i] = i ;   A[i]+=A[i-1] ;
    }*/
    A[0] = Ai[0] = 0 ; 
    for(i = 1 ; i <= n ; ++ i) {
         scanf("%I64d" , &A[i]);   Ai[i] = i ; A[i]+=A[i-1] ;
    }
    //printf("A[1..n] = "); for(i = 1 ; i <= n ; ++ i)  printf("  %I64d" , A[i]);  printf("\n");
    qs(A , Ai , 1 , n);
    for(i = 0 ;i<=n ; ++i)   b[Ai[i]] = i ;                   // printf("sorted A[1..n] = "); for(i = 1 ; i <= n ; ++ i)  printf("  %I64d" , A[i]);  printf("\n");
    for(i = 0 ;i<=n ; ++i)   tr[1][i] = b[i] , c[i] = 2 ;     // printf("b[1..n] = ");  for(i = 1 ; i<=n ;++i)  printf(" %I64d" , b[i]);  printf("\n");
    for(i = 0 ; i < maxk ; ++ i)  s[i][0] = 0 ;
    build(1 , 1 , n );  hs = 0 ; // init the heap 
    for(i = 0 ;i<=n ; ++i)
       if(i+L<=n){
            l = i+L ;  r = (i+R<= n ? i+R : n); 
                opt =  A[getkth(1 , 1 , n , l , r , 1)] - A[b[i]] ;   // printf("inteval[%I64d ,%I64d] index = %I64d  opt = %I64d\n" , l , r ,i , opt);
                ++ hs ; h[hs].x = opt ;  h[hs].pos = i ;  up(hs) ;
       }
    ans = 0 ;  
    for(i = 1 ; i <= K ; ++ i){
           //printf("value = %I64d\n" , h[1].x  );
           ans += h[1].x  ;   pos = h[1].pos ;  
           h[1] = h[hs--]  ;  down(1) ;  // delete the maximal value in heap
           l = pos + L ;   r = (pos+R<= n ?  pos+R : n ) ;  // printf("A[%d] = %I64d\n" , 3 , A[b[3]] );
           if(c[pos] <= r-l+1){
                opt = A[getkth(1 , 1 , n , l , r , c[pos])] - A[b[pos]] ;   ++ c[pos] ;    //printf("inteval[%I64d ,%I64d] index = %I64d  opt = %I64d\n" , l , r ,pos , opt);
                ++ hs ;  h[hs].x = opt ; h[hs].pos = pos ; up(hs) ; 
           } 
    }
    printf("%I64d\n" , ans);     
    //system("pause");
    return 0 ;
}
