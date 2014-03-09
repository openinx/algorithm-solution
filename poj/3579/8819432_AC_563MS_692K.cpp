#include<iostream>
#include<algorithm>
using namespace std ;

typedef __int64 lld ;

const lld MAXN = 100005 ;
const lld MAX_INT = 2100000000  ;

lld n , a[MAXN] ;
lld q[MAXN], head , tail ;

lld calc(lld M ){
    lld i , tot = 0 ; 
    head = 0 , tail = -1 ; 
    for(i = 1 ; i <= n ; ++ i){
         while(tail>=head && M + q[head] < a[i])  head ++ ;
         if(tail>=head)  tot += tail-head+1 ;
         q[++tail] = a[i] ;
    }
    return tot ;
}

int main(){
    lld i , l , r , mid , ans ;
    lld target ;
    while(scanf("%I64d" , &n)!=EOF){
       for(i = 1 ; i <= n ; ++ i)  scanf("%I64d" , &a[i]);
       sort(a + 1 , a + n + 1 );
  
       target = (lld)n*((lld)(n-1))/2 ;
       if(target%2 == 0)  target = target/2 ;
       else target = target/2 + 1;
       l = 0 , r = MAX_INT  , ans = 0 ;             
       while(l <= r ){
             mid = (l + r)>>1 ;
             if(calc(mid)<= target-1){
                   l = mid + 1 ; ans = mid ;
             }else{
                   r = mid - 1 ;
             }
       }
       if(calc(ans) < target)  
          ans ++ ;
       printf("%I64d\n" , ans);
    }
    return 0 ;
}
