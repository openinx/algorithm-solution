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
            t = i / 2 * (i - 1) % BIG_PRIME ;
        else
            t = ( i - 1) / 2 * i % BIG_PRIME ; 
        invs[i] = ( ( i * invs[i-1]  ) % BIG_PRIME +  ( fac[i-1] * t ) % BIG_PRIME ) % BIG_PRIME ;
    }
    //for(i = 1 ; i <= 6 ; ++ i) printf("invs[%lld]=%lld\n", i, invs[i]) ;
}

lld lowbit(lld x){
    return x & ( - x) ;
}

void insert(lld x, lld del){
    for(lld i = x ; i <= n ; i += lowbit(i))
        bit[i] = (bit[i] + del) % BIG_PRIME ;
}

lld sum(lld x){
    lld ans = 0 ;
    for(lld i = x; i>=1 ; i -=lowbit(i))
        ans =  (ans + bit[i]) % BIG_PRIME ; 
    return ans ; 
}

int main(){
    init();

    lld i , result = 0 ; 
    while(scanf("%lld", &n) !=EOF )
    {
        for(i = 1; i <= n; ++ i) scanf("%lld", &p[i]);
        result = 0 ;
        memset(bit, 0 , sizeof(bit)) ;
        lld sv = 0 , t, b;

        for(i = 1 ; i <= n; ++ i){
           // from [i+1..n]
           b = ( p[i] - 1 - sum(p[i]) )  % BIG_PRIME ; 
           result = (result +  b * invs[n - i] % BIG_PRIME ) % BIG_PRIME ; 
           // from [i..i]
           lld tb = b * (b - 1) / 2 % BIG_PRIME ;
           result = (result + tb * fac[n - i] % BIG_PRIME ) % BIG_PRIME ;
           // from [0..i-1]
           t = ( sv * b % BIG_PRIME ) * fac[n - i] % BIG_PRIME ; 
           result = (result + t) % BIG_PRIME ; 
           //p[0], p[1], p[2]...p[i-1] participate  inversions (p[k], x); (0<=k<=i-1)
           sv = (sv + (p[i] - 1 - sum(p[i])) ) % BIG_PRIME ; 
           insert(p[i], 1) ;

           //printf("###%lld\n", sv) ;
           //printf("$ :%lld\n", result) ;

        }
        //printf("%lld\n", sv) ;
        printf("%lld\n",  (result + sv) % BIG_PRIME );
        //memset(bit, 0 , sizeof(bit)) ; 

        //for(i = 0 ; i < n ; ++ i)   {
            //printf("$: %lld\n", p[i]) ; 
            //printf("#: %lld\n", i - sum(p[i])) ;
         //   result =  (result + ( i - sum(p[i])) ) % BIG_PRIME ; 
          //  insert(p[i], 1) ; 
        //}
        //printf("%lld\n", result) ;
    }
    return 0 ;
}

