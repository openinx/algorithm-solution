#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std ; 

typedef long long lld ; 

#define MAXN 100000 

lld prime[MAXN], is[MAXN] , size ; 

void init_prime(){
    lld i, j ;
    memset(is, 0 , sizeof(is)) ; 
    size = 0; 
    for(i = 2 ; i < MAXN ; ++ i){
        if (is[i] == 0 )
        {
            prime[size ++ ] = i ; 
            for(j = i + i ; j < MAXN ; j += i)
                is[j] = 1 ; 
        }
    }
}

lld is_prime(lld x){
    lld i ; 
    for(i = 0 ;i < size ; ++ i)
        if ((x > prime[i]) && (x % prime[i] == 0 ))
            return 0 ; 
    return 1 ; 
}

lld gcd(lld x , lld y ){
    return y == 0 ?  x: gcd(y, x % y )  ; 
}


lld get_v(lld x){
    while(!is_prime(x)) x -- ;
    return x ;
}

lld get_u(lld x){
    x ++ ; 
    while(!is_prime(x)) x ++ ;
    return x ; 
}

int main(){

    init_prime();
    //for(int i = 0 ; i < size; ++ i) printf("%lld\n", prime[i]);

    lld t , n ; 
    //printf("%lld\n", gcd((lld)999999941999999673, (lld)499999970999999805 )) ; 

    scanf("%lld", &t) ; 
    while(t--){
        scanf("%lld", &n);
        lld p1 = get_v(n) ;
        lld p2 = get_u(n) ; 
        lld x = p1 * p2 + 2 * n  - 2 * p2  - 2 * p1 + 2 ;
        lld y = 2 * p1 * p2 ; 
        lld c = gcd(y, x);
        printf("%lld/%lld\n", x/c , y/c);
    }
    return 0 ; 
}

