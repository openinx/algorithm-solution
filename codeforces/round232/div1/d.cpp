#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std ; 

typedef long long lld ;

#define MAXN        1000005 
#define BIG_PRIME   1000000007

lld  p[MAXN] , fac[MAXN] , n, invs[MAXN], bit[MAXN];

void init(){
    lld i ; 
    fac[1] = 1 ;
    for(i = 2 ; i < MAXN; ++ i)
        fac[i] =  ( fac[i-1] * i  ) % BIG_PRIME ;
    //for(i = 1 ; i <= 5 ; ++ i) printf("fac[%lld]=%lld\n", i, fac[i]) ;
    memset(invs, 0 , sizeof(invs)); 
    invs[1]  = invs[0] = 0 ; 
    for(i = 2 ; i < MAXN; ++ i)  {
        lld t  ; 
        if (i % 2 == 0 )
            t = i / 2 * (i - 1) ;
        else
            t = ( i - 1) / 2 * i ; 
        invs[i] = ( ( i * invs[i-1]  ) % BIG_PRIME +  ( fac[i-1] * t ) % BIG_PRIME ) % BIG_PRIME ;
    }
    //for(i = 1 ; i <= 5 ; ++ i) printf("invs[%lld]=%lld\n", i, invs[i]) ;
}

lld lowbit(lld x){
    return x & ( - x) ;
}

void insert(lld x, lld del){
    for(lld i = x ; i <= n ; i += lowbit(i))
        bit[i] += del;
}

lld sum(lld x){
    lld ans = 0 ;
    for(lld i = x; i>=1 ; i -=lowbit(i))
        ans += bit[i] ; 
    return ans ; 
}

int main(){
    init();

    lld i , result = 0 ; 
    while(scanf("%lld", &n) !=EOF )
    {
        for(i = 0 ; i < n; ++ i) scanf("%lld", &p[i]);
        result = 0 ;
        memset(bit, 0 , sizeof(bit)) ;
        lld sv = 0 , t, pi_less , pi_less_unused;
        for(i = 0 ; i < n; ++ i){
           pi_less = sum(p[i]) ; 
           pi_less_unused = p[i] - 1 - pi_less ; 
           result = (result + pi_less_unused * invs[n - i]) % BIG_PRIME ; 
           t = sv * pi_less_unused % BIG_PRIME ; 
           t = t * fac[n - i - 1] % BIG_PRIME ; 
           result = (result + t) % BIG_PRIME ; 
           //p[0], p[1], p[2]...p[i-1] participate  inversions (p[k], x); (0<=k<=i-1)
           sv = (sv + (i - sum(p[i])) ) % BIG_PRIME ; 
           insert(p[i], 1) ;
        }
        printf("%lld\n",  result);
        //memset(bit, 0 , sizeof(bit)) ; 

        //for(i = 0 ; i < n ; ++ i)   {
            //printf("$: %lld\n", p[i]) ; 
            //printf("#: %lld\n", i - sum(p[i])) ;
         //   result =  (result + ( i - sum(p[i])) ) % BIG_PRIME ; 
          //  insert(p[i], 1) ; 
        //}
        //printf("%lld\n", result) ;
    }
}

